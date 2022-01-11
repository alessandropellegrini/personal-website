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
[1](timewarp1.pdf)
[2](timewarp2.pdf)
[3](timewarp3.pdf)
[4](timewarp4.pdf)
[5](timewarp5.pdf)
[6](timewarp6.pdf).

1. **NUMA Aware Load-Sharing Policy**    
   In this thesis, a decision-making module should be designed and implemented. The goal is to determine, at runtime, the best-suited placement for LPs, worker threads, and memory pages in a NUMA architecture. See this supporting material for an additional framing of the topic: [1](numa.pdf).
1. **Model-related fossil collection**    
   This thesis tackles the design and implementation of a transparent module to allow simulation models to perform fossil collection.
1. **Spiking Neural Networks**     
   Spiking neural networks (SNN) are among the most computationally intensive types of simulation models, with node counts on the order of up to 10^11. This thesis tackles the implementation of efficient runtime environments for SNN simulation on parallel and distributed architectures. See this supporting material for an additional framing of the topic: [1](timewarp7.pdf), [2](timewarp8.pdf).
1. **Termination Detection**     
   In speculative simulation, accurate termination detection could be an issue, performancewise. This thesis tackles the design of different algorithms which allow to identify a global termination condition in a model-independent way, with different accuracy/performance tradeoffs. See this supporting material for an additional framing of the topic: [1](../publications/Qua09.pdf), [2](../publications/Cuc07.pdf).

### Energy Efficiency

Theses in this field tackle with the problem of identifying a suitable trade-off between performance and energy consumption. The body of work in this area targets methodologies and techniques to allow for an automatic identification of the power/energy/performance level which maximizes the overall efficiency of the application.

To get more information on this thesis topic, you can read the following papers:
[1](energy0.pdf)
[2](energy1.pdf)
[3](energy2.pdf)
[4](energy3.pdf).

1. **Daemon to manage consumption**    
   Define an interface for low-overhead power management of the system. Define masks to set P-state of multiple cores with a single system call. The daemon should communicate with non-root process to allow them to self-tune power without required superuser privilege. In addition to P-state, should also allow enabling or disabling SMT and turbo boost.

### Non-Blocking Algorithms

Non-blocking algorithms are a family of concurrent algorithms which enforce correctness by relying on fine-grain synchronization hardware instructions, globally termed Read-Modify-Write instructions. Theses in this family address the implementation of data structures which support a massive number of concurrent operations by relying on this form of fine-grain synchronization.

To get more information on this thesis topic, you can read the following papers:
[1](waitfree1.pdf)
[2](waitfree2.pdf)

1. **Locality-aware non-blocking priority queue**    
   The goal of this thesis is to design and implement a non-blocking priority queue which exhibits increased performance thanks to the exploitation of memory locality.

### Heterogeneous Architectures

Heterogeneous architectures are computer architecture in which there are several different families of processing units (CPUs, GPUs, Coprocessors, low-energy cores, etc.) which can be exploited simultaneously. The theses reported here target this family of architectures.

1. **Time Warp on GPU**    
   Implementation of a GPU-oriented Time Warp scheduler (see the support material in the section on High Performance Simulation for a description of Time Warp).
1. **Hybrid Binary**    
   Definition and implementation of software support to generate and manage hybrid binaries for heterogeneous architectures.

### Computer Architectures

No theses available at the moment.


### Cybersecurity

No theses available at the moment.



## Theses Archive

Below, you can find a list of Bachelor's (a selection), Master's, and PhD thesis which I have been involved in supervising, or which belong to my research group. They could serve as an indication of the kind of work which is carried out by my research group.

{% bibliography -q @mastersthesis @phdthesis %}

