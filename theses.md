---
layout: default
title: Theses Proposals
permalink: /theses/
---

This page reports (as much as I can) about vacant theses assignments which can be carried out with the instructor. For additional information, come to office hours or send an email to the instructor.

## *Message To Prospective Students*

*My research program is very software-intensive, focusing largely in the area of parallel and distributing computing, performance evaluation, modeling and computer simulation, computer architectures, operating systems. If you wish to work with me on a Master's Thesis, please consider the following checklist before:*

* *I am not scared to write in C, and I have a strong desire to work with software very intensely.* 
* *I have been exposed to some low-level assembly language programming like x86 or ARM, MIPS or other, and it has been an interesting expecience.*
* *I have been using UNICES (Linux, FreeBSD or other variants) happily for a while.*
* *I have been exposed to parallel programming ( `pthreads`, MPI, OpenMP).*
* *I have fun with algorithms.*
* *I'm not scared by mathematical and logical modeling.*

*If your recognize yourself (even partially) in the above profile, or if you would like to increase your skills in some of the above points, please send me an email!*

*I look forward to hearing from you!*


## Theses Topics at a glance

### High Performance Simulation

Theses in the field of High Performance Simulation tackles topics related to the design and development of distributed and highly-parallel runtime environments to support the execution of generic simulation models according to a speculative processing paradigm. Some theses target the definition and implementation of simulation models relying on this paradigm.

To get more information on this thesis topic, you can read the following papers:
[1](theses/timewarp1.pdf)
[2](theses/timewarp2.pdf)
[3](theses/timewarp3.pdf)
[4](theses/timewarp4.pdf)
[5](theses/timewarp5.pdf)
[6](theses/timewarp6.pdf).

1. **Asymmetric Time Warp**    
   This thesis addresses the implementation of an asymmetric multithreaded runtime environment to support PDES. In the asymmetric approach, different threads carry out different activities, in order to maximise performance and minimise energy consumption. An analytical model shall determine, at runtime, every thread of the system what incarnation has, for a part of the lifetime of the application.
1. **NUMA Aware Load-Sharing Policy**    
   In this thesis, a decision-making module should be designed and implemented. The goal is to determine, at runtime, the best-suited placement for LPs, worker threads, and memory pages in a NUMA architecture. See this supporting material for an additional framing of the topic: [1](theses/numa.pdf).
1. **Model-related fossil collection**    
   This thesis tackles the design and implementation of a transparent module to allow simulation models to perform fossil collection.
1. **ABM for evacuation plans**    
   The goal of this thesis is the implementation of an ABM model to study the emergent behavior of people during the evacuation of a building.
1. **Compiler support to intercept arbitrary memory accesses**    
   The goal of this thesis is to realize innovative compiler-assisted software modules to increment the efficiency of incremental state saving.
1. **Hardware-Based Incremental State Saving**    
   The goal of this thesis is to rely on modern-CPU hardware facilities to implement incremental state saving. See this supporting material for an additional framing of the topic: [1](theses/pmu.pdf) [2](theses/IBS.pdf).

### Energy Efficiency

Theses in this field tackle with the problem of identifying a suitable trade-off between performance and energy consumption. The body of work in this area targets methodologies and techniques to allow for an automatic identification of the power/energy/performance level which maximizes the overall efficiency of the application.

To get more information on this thesis topic, you can read the following papers:
[1](theses/energy0.pdf)
[2](theses/energy1.pdf)
[3](theses/energy2.pdf)
[4](theses/energy3.pdf).

1. **Daemon to manage consumption**    
   Define an interface for low-overhead power management of the system. Define masks to set P-state of multiple cores with a single system call. The daemon should communicate with non-root process to allow them to self-tune power without required superuser privilege. In addition to P-state, should also allow enabling or disabling SMT and turbo boost.
2. **Fine-grain Simultaneous Multi Threading**    
   SMT can increase applications performance by up to 40% (Intel HT 2 way)  with very limited increase in power consumption. However this speed-up is highly performance-dependent and its use might even lead to a performance degradation. Moreover, applications generally are typically composed of different threads which might show a different workload, and thus, different SMT effectiveness. The goal of this thesis is to allow portions of threads of a single application to enable SMT while for others is still disabled. This could either be achieved at system level (TCB and scheduler modifications) or with an external module and affinity. Measuring the performance/power trade-offs for different applications is also part of this thesis.
3. **Effective exploration of P-state configurations**    
   In the context of multi-threaded applications, we want to build an exploration policy which does not violate a specified power cap while collecting the data to support the prediction model.
4. **Advanced exploration-based powercap**    
   Devising exploration strategies which are resilient to local maxima/minima to build prediction model of massively parallel p-state configurations.
5. **Synthetic Benchmark Generation from real-world applications**    
   The goal of this thesis is to generate a synthetic program starting from a real application, which has a very short duration but is meaningful from a workload point of view with respect to the original application. This generation shall be done using hardware performance counters. See this supporting material for an additional framing of the topic: [1](theses/pmu.pdf) [2](theses/IBS.pdf).

### Non-Blocking Algorithms

Non-blocking algorithms are a family of concurrent algorithms which enforce correctness by relying on fine-grain synchronization hardware instructions, globally termed Read-Modify-Write instructions. Theses in this family address the implementation of data structures which support a massive number of concurrent operations by relying on this form of fine-grain synchronization.

To get more information on this thesis topic, you can read the following papers:
[1](theses/waitfree1.pdf)
[2](theses/waitfree2.pdf)

1. **Locality-aware non-blocking priority queue**    
   The goal of this thesis is to design and implement a non-blocking priority queue which exhibits increased performance thanks to the exploitation of memory locality.

### Heterogeneous Architectures

Heterogeneous architectures are computer architecture in which there are several different families of processing units (CPUs, GPUs, Coprocessors, low-energy cores, etc.) which can be exploited simultaneously. The theses reported here target this family of architectures.

1. **Time Warp on GPU**    
   Implementation of a GPU-oriented Time Warp scheduler (see the support material in the section on High Performance Simulation for a description of Time Warp).
1. **Hybrid Binary**    
   Definition and implementation of software support to generate and manage hybrid binaries for heterogeneous architectures.

### Computer Architectures

1. **Domain-Specific Language and Visual Tools to describe Device Drivers**    
   The goal of this thesis is to design and implement a Domain-Specific Programming Language to describe the internal operations of device drivers in a simulator. During the thesis work, it will be developed a parser and a runtime interpreter of the language.    Moreover, the thesis will deal with the implementation of a visual tool to allow the visual construction of device interfaces. The tool will have to respond to signals/generate signals, and will have to support a minimal set of animations.


### Cybersecurity

1. **`Unveil()`**    
   Design and implementation of a BSD `unveil()`-like system to support mandatory filesystem access.
1. **~~Meltdown/Spectre Disclosure using Hardware Support~~ `[assigned]`**     
   Implementation of a hardware-based detection system for Meltdown/Spectre attacks.
1. **Security against Malicious Loadable Kernel Modules**    
   Design and implementation of a set of patches to protect the Linux kernel from malicious modules.
