---
layout: default
title: Theses Proposals
permalink: /theses/
---

This page reports (as much as I can) about current vacant theses assignments which can be carried out with me. For additional information, come to office hours or send an email to the instructor.

## *Message To Prospective Students*

*My research program is very software-intensive, focusing largely in the area of parallel and distributing computing, performance evaluation, modeling and computer simulation, computer architectures, operating systems. If you wish to work with me on a Master's Thesis, please consider the following checklist before:*

* *I am not scared to write in C, and I have a strong desire to work with software very intensely.* 
* *I have been exposed to some low-level assembly language programming like x86 or ARM, MIPS or other, and it has been an interesting expecience.*
* *I have been using UNICES (Linux, FreeBSD or other variants) happily for a while.*
* *I have been exposed to parallel programming ( `pthreads`, MPI, OpenMP).*
* *I have fun with algorithms.*
* *I'm not scared by mathematical and logical modeling.*

*If you recognize yourself (even partially) in the above profile, or if you would like to increase your skills in some of the above points, please send me an email!*

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

### Spiking Neural Networks

Spiking neural networks (SNN) are among the most computationally intensive types of simulation models, with node counts on the order of up to 10^11. This thesis topic tackles the implementation of efficient runtime environments for SNN simulation on parallel and distributed architectures. See this supporting material for an additional framing of the topic: [1](timewarp7.pdf), [2](timewarp8.pdf).

### High-Performance Data Processing

We are building a high-performance software infrastructure to support (distributed) data processing of massively-parallel simulations. Theses in this topic deal with distributed systems, high-performance computing, autonomic optimization. There is the **possibility to develop the thesis abroad**.

### Energy Efficiency

Theses in this field tackle with the problem of identifying a suitable trade-off between performance and energy consumption. The body of work in this area targets methodologies and techniques to allow for an automatic identification of the power/energy/performance level which maximizes the overall efficiency of the application.

To get more information on this thesis topic, you can read the following papers:
[1](energy0.pdf)
[2](energy1.pdf)
[3](energy2.pdf)
[4](energy3.pdf).

### Non-Blocking Algorithms

Non-blocking algorithms are a family of concurrent algorithms which enforce correctness by relying on fine-grain synchronization hardware instructions, globally termed Read-Modify-Write instructions. Theses in this family address the implementation of data structures which support a massive number of concurrent operations by relying on this form of fine-grain synchronization.

To get more information on this thesis topic, you can read the following papers:
[1](waitfree1.pdf)
[2](waitfree2.pdf)

### Heterogeneous Architectures

Heterogeneous architectures are computer architectures in which there are several different families of processing units (CPUs, GPUs, Coprocessors, low-energy cores, etc.) which can be exploited simultaneously. In this context, we are studying how to make different hardware classes interact to reach a common (synchronized) processing goal. There is the **possibility to develop the thesis abroad**.


### Cybersecurity

In the context of cybersercurity, we are mostly dealing with defensive security. The main topics are related to Intellectual Property Preservation, File System Security, Kernel-Level Authorization, AV detection, and full-stack infrastructure monitoring.



## Theses Archive

Below, you can find a list of Bachelor's (a selection), Master's, and PhD thesis which I have been involved in supervising, or which belong to my research group. They could serve as an indication of the kind of work which is carried out by my research group.

{% bibliography -q @mastersthesis @phdthesis %}

