---
layout: default
title: Theses Proposals
permalink: /theses/
---

This page reports (as much as I can) about current vacant thesis assignments which can be carried out with me. For additional information, come to office hours or email the instructor.

## *Message To Prospective Students*

*My research program is very software-intensive, focusing largely on the area of parallel and distributed computing, performance evaluation, modelling and computer simulation, computer architectures, and operating systems. If you wish to work with me on a Master's Thesis, please consider the following checklist before:*

* *I am not scared to write in C, and I have a strong desire to work with software very intensely.* 
* *I have been exposed to some low-level assembly language programming like x86 or ARM, MIPS or others, and it has been an interesting experience.*
* *I have been using UNICES (Linux, FreeBSD or other variants) happily for a while.*
* *I have been exposed to parallel programming ( `pthreads`, MPI, OpenMP).*
* *I have fun with algorithms.*
* *I'm not scared by mathematical and logical modelling.*

*If you recognise yourself (even partially) in the above profile, or if you would like to increase your skills in some of the above points, please send me an email!*

*I look forward to hearing from you!*


## Theses Topics at a glance

### High Performance Simulation

Theses in the field of High Performance Simulation tackle topics related to the design and development of distributed, highly parallel runtime environments to support the execution of generic simulation models using a speculative processing paradigm. Some theses target the definition and implementation of simulation models relying on this paradigm.

To get more information on this thesis topic, you can read the following papers:
[1](timewarp1.pdf)
[2](timewarp2.pdf)
[3](timewarp3.pdf)
[4](timewarp4.pdf)
[5](timewarp5.pdf)
[6](timewarp6.pdf).


Additional topics concern the identification of optimal computation placement in complex heterogeneous systems to achieve improved performance while saving energy.

### Heterogeneous Architectures

Heterogeneous architectures are computer architectures that combine several families of processing units (CPUs, GPUs, Coprocessors, low-energy cores, etc.) that can be exploited simultaneously. In this context, we are studying how to make different hardware classes interact to reach a common (synchronised) processing goal. We tackle this problem both from the bottom up and the top down: we work on runtime environments and devices, and we also use logic programming and optimisation techniques to optimise workload placement at runtime.

### Software Engineering

We are exploring Model-Driven Engineering techniques to support the deployment and orchestration of complex applications targeting different hardware and software architectures.


### Cybersecurity

In the context of cybersecurity, we primarily deal with defensive security. The main topics are related to code obfuscation, virtualisation, self-modifying binaries, and metamorphism. The approach we tackle is profoundly based on low-level manipulation of code and data, driven by high-level tools proper to Theoretical Computer Science.



## Theses Archive

Below, you can find a list of Bachelor's (a selection), Master's, and PhD thesis which I have been involved in supervising, or which belong to [my research group](https://hpdcs.github.io/). They could serve as an indication of the kind of work which is carried out by my research group.

{% bibliography -q @mastersthesis @phdthesis %}

