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


Additional topics regard the identification of the optimal placement of computation in complex heterogeneous systems, to identify optimal configurations that can improve performance while saving on energy.

### Heterogeneous Architectures

Heterogeneous architectures are computer architectures in which there are several different families of processing units (CPUs, GPUs, Coprocessors, low-energy cores, etc.) which can be exploited simultaneously. In this context, we are studying how to make different hardware classes interact to reach a common (synchronized) processing goal. We tackle this problem both from the bottom up and top down: we work on runtime environments, on devices, but also we use logic programming and optimization techniques to optimize the workload placement at runtime.

### Software Engineering

We are exploring Model-Driven Engineering techniques to support the deployment and orchestration of complex applications targeting different hardware and software architectures.


### Cybersecurity

In the context of cybersercurity, we are mostly dealing with defensive security. The main topics are related to code obfuscation, virtualization, self-modifying binaries, and metamorphism. The approach we tackle is profoundly based on low-level manipulation of code and data, driven by high level tools proper of Theoretical Computer Science.



## Theses Archive

Below, you can find a list of Bachelor's (a selection), Master's, and PhD thesis which I have been involved in supervising, or which belong to [my research group](https://hpdcs.github.io/). They could serve as an indication of the kind of work which is carried out by my research group.

{% bibliography -q @mastersthesis @phdthesis %}

