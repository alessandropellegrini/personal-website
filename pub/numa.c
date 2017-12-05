#define _GNU_SOURCE
#include <sched.h>  // <-- To set the affinity of the thread
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>
#include <numa.h>   // <-- To access libnuma
#include <numaif.h>   // <-- To access libnuma
#include <string.h>
#include <stdint.h>

//#define INTERFERENCE
#define INTERFERENCE_COUNT 2
//#define INTERFERENCE_COUNT cpus

#define TOTAL_MEMORY 262144L * PAGE_SIZE // This is 1 GB 
#define PAGE_SIZE 	(4L*1<<10)
#define ACCESS_COUNT	50000000

// Stuff to measure execution time
#define timer_start(timer_name)		gettimeofday(&timer_name, NULL)
#define timer_value_milli(timer_name) ({\
					struct timeval __tmp_timer;\
					int __timedif;\
					gettimeofday(&__tmp_timer, NULL);\
					__timedif = __tmp_timer.tv_sec * 1000 + __tmp_timer.tv_usec / 1000;\
					__timedif -= timer_name.tv_sec * 1000 + timer_name.tv_usec / 1000;\
					__timedif;\
			   	       })

// To measure the time taken by memory accesses
static struct timeval timer;

// To invalidate caches more efficiently
static size_t llc_size, llc_line;

// Data structures to to move pages on a specific NUMA node
static char *pages[TOTAL_MEMORY / PAGE_SIZE];
static int   nodes[TOTAL_MEMORY / PAGE_SIZE];
static int   status[TOTAL_MEMORY / PAGE_SIZE];
static int node_count;
static int cpus;

// A pointer to our memory
static unsigned char *vector;


// Discover cache size and cache line size

void amd_cpuid_caches(void) {
	uint32_t eax, ebx, ecx, edx;
	size_t l1d_size, l1i_size, l2u_size;
	size_t line;

	eax = 0x80000005; // L1 cache and TLB information

	asm volatile (
            "cpuid" // call i386 cpuid instruction
            : "+a" (eax) // contains the cpuid command code
            , "=b" (ebx)
            , "=c" (ecx) 
            , "=d" (edx)
        ); // generates output in 4 registers eax, ebx, ecx and edx

	l1d_size = ((ecx >> 24) & 0xFF) * 1024;
	l1i_size = ((edx >> 24) & 0xFF) * 1024;
	line = (ecx && 0xFF);

	eax = 0x80000006; // L2 cache information

	asm volatile (
            "cpuid" // call i386 cpuid instruction
            : "+a" (eax) // contains the cpuid command code
            , "=b" (ebx)
            , "=c" (ecx) 
            , "=d" (edx)
        ); // generates output in 4 registers eax, ebx, ecx and edx

	l2u_size = ((ecx >> 16) & 0xFFFF) * 1024;
	if(l2u_size > 0)
		line = (ecx & 0xFF);

	printf(
		"L1D size: %zu\n"
		"L1I size: %zu\n"
		"L2U size: %zu\n"
		"Line: %zu\n",
		l1d_size,
		l1i_size,
		l2u_size,
		line);

	llc_size = l2u_size;
	llc_line = line;

}

void intel_cpuid_caches(void) {
    int i;
    size_t cache_total_size;
    size_t cache_coherency_line_size;

    for (i = 0; i < 32; i++) {

        // Variables to hold the contents of the 4 i386 legacy registers
        uint32_t eax, ebx, ecx, edx; 

        eax = 4; // get cache info
        ecx = i; // cache id

        asm volatile (
            "cpuid" // call i386 cpuid instruction
            : "+a" (eax) // contains the cpuid command code, 4 for cache query
            , "=b" (ebx)
            , "+c" (ecx) // contains the cache id
            , "=d" (edx)
        ); // generates output in 4 registers eax, ebx, ecx and edx 

        // taken from http://download.intel.com/products/processor/manual/325462.pdf Vol. 2A 3-149
        int cache_type = eax & 0x1F; 

        if (cache_type == 0) // end of valid cache identifiers
            continue;

        char * cache_type_string;
        switch (cache_type) {
            case 1: cache_type_string = "Data Cache"; break;
            case 2: cache_type_string = "Instruction Cache"; break;
            case 3: cache_type_string = "Unified Cache"; break;
            default: cache_type_string = "Unknown Type Cache"; break;
        }

        int cache_level = (eax >>= 5) & 0x7;

        int cache_is_self_initializing = (eax >>= 3) & 0x1; // does not need SW initialization
        int cache_is_fully_associative = (eax >>= 1) & 0x1;


        // taken from http://download.intel.com/products/processor/manual/325462.pdf 3-166 Vol. 2A
        // ebx contains 3 integers of 10, 10 and 12 bits respectively
        unsigned int cache_sets = ecx + 1;
        cache_coherency_line_size = (ebx & 0xFFF) + 1;
        unsigned int cache_physical_line_partitions = ((ebx >>= 12) & 0x3FF) + 1;
        unsigned int cache_ways_of_associativity = ((ebx >>= 10) & 0x3FF) + 1;

        // Total cache size is the product
        cache_total_size = cache_ways_of_associativity * cache_physical_line_partitions * cache_coherency_line_size * cache_sets;

        printf(
            "Cache ID %d:\n"
            "- Level: %d\n"
            "- Type: %s\n"
            "- Sets: %d\n"
            "- System Coherency Line Size: %zu bytes\n"
            "- Physical Line partitions: %d\n"
            "- Ways of associativity: %d\n"
            "- Total Size: %zu bytes (%zu kb)\n"
            "- Is fully associative: %s\n"
            "- Is Self Initializing: %s\n"
            "\n"
            , i
            , cache_level
            , cache_type_string
            , cache_sets
            , cache_coherency_line_size
            , cache_physical_line_partitions
            , cache_ways_of_associativity
            , cache_total_size, cache_total_size >> 10
            , cache_is_fully_associative ? "true" : "false"
            , cache_is_self_initializing ? "true" : "false"
        );
    }

    llc_size = cache_total_size;
    llc_line = cache_coherency_line_size;
}

void cache_discovery(void) {
	uint32_t eax, ebx, ecx, edx;
	char vendor[sizeof(uint32_t) * 3 + 1] = { 0 };
	char *vptr = vendor;

	// Call Intel or AMD function depending on the vendor
	eax = 0; // get vendor info

        asm volatile (
            "cpuid" // call i386 cpuid instruction
            : "+a" (eax) // contains the cpuid command code, 4 for cache query
            , "=b" (ebx)
            , "=c" (ecx)
            , "=d" (edx)
        );
	memcpy(vptr, (char *)&ebx, sizeof(uint32_t));
	vptr += sizeof(uint32_t);
	memcpy(vptr, (char *)&edx, sizeof(uint32_t));
	vptr += sizeof(uint32_t);
	memcpy(vptr, (char *)&ecx, sizeof(uint32_t));
	vptr += sizeof(uint32_t);


	if(strcmp("AuthenticAMD", vendor) == 0) {
		printf("AMD CPU found\n");
		amd_cpuid_caches();
	} else if(strcmp("GenuineIntel", vendor) == 0) {
		printf("Intel CPU found\n");
		intel_cpuid_caches();
	} else {
		printf("Neither Intel or AMD CPU detected. Exiting...\n");
		exit(EXIT_FAILURE);
	}
}


// This functions move our memory to a given NUMA node asynchronously
void _move_pages(int numa_node) {
	int pagecount;
	int i;
	unsigned char *segment_addr;
	int ret;

	pagecount = TOTAL_MEMORY / PAGE_SIZE - 1;
	segment_addr = vector;

	for (i = 0; i < pagecount; i++){
		pages[i] = segment_addr + i * PAGE_SIZE;
		nodes[i] = numa_node;
		status[i] = node_count + 1; // This is not a valid status value
	}
	ret = numa_move_pages(0, pagecount, (void **)pages, nodes, status, MPOL_MF_MOVE);
	if(ret == -1) {
		perror("numa_move_pages");
	}
}

void *do_move_pages(void *numa_node) {
	int node = (int)numa_node;
	_move_pages(node);
	return NULL;
}


void wait_for_migration(int node) {
	int i = 0;
	bool finished;
	int pagecount = TOTAL_MEMORY / PAGE_SIZE;
	int missing = pagecount;
	int retry = 0;

	do {
		printf("Waiting for migration: still %d pages to migrate\n", missing);
		missing = 0;
		finished = true;
		for(i = 0; i < pagecount; i++) {
			if(status[i] != node) {
				missing++;
				finished = false;
			}
		}
		if(retry++ == 10)
			break;
	} while(!finished);
}

// This flushes cache lines associated with vector
void cacheflush(void) {
	int i;
	int lines = llc_size / llc_line;

	for(i = 0; i < lines; i += llc_line) {
		asm volatile ("clflush %0":: "m" (vector[i]));
	}
}

// Perform random acces in write mode on data
void do_access(void) {
	int i, access;

	srand(time(NULL));
	cacheflush(); // Just to avoid that we are caching anything useful

	for(i = 0; i < ACCESS_COUNT; i++) {
		access = rand() % TOTAL_MEMORY;
		vector[access] = 'a';
	}
}


#ifdef INTERFERENCE
void *interference(void *core) {
	cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
	CPU_SET(((int)core + cpus/2) % cpus, &cpuset); // 0 is CPU 0
	sched_setaffinity(0, sizeof(cpuset), &cpuset); // 0 means 'current thread'
	
	while(1) {
		do_access();
	}
}
#endif



int main(void) {
	cpu_set_t cpuset;
	int remote_time, migration_time, local_time;
	pthread_t numa_tid;
	int i;

	// Check if we are on a NUMA architecture
	if(numa_available() < 0) {
		printf("Not on a NUMA architecture\n");
		exit(EXIT_FAILURE);
	}

	cache_discovery();

	node_count = numa_num_configured_nodes();
	cpus = numa_num_configured_cpus();
	printf("This machine has %d NUMA nodes and %d CPUs\n\n", node_count, cpus);

	// Stick the current thread on cpu 0, which is NUMA node 0
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset); // 0 is CPU 0
	sched_setaffinity(0, sizeof(cpuset), &cpuset); // 0 means 'current thread'

	// Allocate memory on a remote NUMA node and initialize pages
	printf("Allocate memory on node %d\n", node_count - 1);
	vector = numa_alloc_onnode(TOTAL_MEMORY, node_count - 1);
	memset(vector, 'p', TOTAL_MEMORY);

#ifdef INTERFERENCE
	// Add some interference
	for(i = 1; i < INTERFERENCE_COUNT; i++) {
		pthread_create(&numa_tid, NULL, interference, (void*)i);
	}
#endif

	// Make the first access
	printf("Access remote memory\n");
	timer_start(timer);
	do_access();
	remote_time = timer_value_milli(timer);

	// Start asynchronous migration on node 0 and repeat the access
	printf("Migrate and access memory\n");
	pthread_create(&numa_tid, NULL, do_move_pages, (void*)0);
	timer_start(timer);
	do_access();
	migration_time = timer_value_milli(timer);

	// Wait for migration to complete, then repeat the access
	wait_for_migration(0);
	printf("Access local memory\n");
	timer_start(timer);
	do_access();
	local_time = timer_value_milli(timer);

	// Report statistics
	printf("Execution time on remote memory: %d milliseconds (%.02f%% slowdown)\n", remote_time, (double)(remote_time-local_time)/local_time*100);
	printf("Execution time while migrating: %d milliseconds (%.02f%% slowdown)\n", migration_time, (double)(migration_time-local_time)/local_time*100);
	printf("Execution time on local memory: %d milliseconds\n", local_time);

	return 0;
}
