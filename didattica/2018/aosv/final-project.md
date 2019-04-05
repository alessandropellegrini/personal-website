---
layout: default
---

# AOSV 2018/2019 Final Project

**<u>Important</u>**: information on how to carry out the project are reported below, in the "How to carry out the work" section. In particular, projects should be developed using [GitHub Classroom](https://classroom.github.com/) (invitation link below). 

## File Access with Sessions

For the final exam project, the student is required to implement a subsystem which allows to access files in a specific directory of the VFS using *sessions*.

The implementation can be made by recompiling the kernel, or by realizing a LKM. The decision is given to the student.

The path to the folder in which files should be accessed must be parameterizable. That is, the Linux subsystem should provide an interface which can be used to specify the path. This path can change at runtime (i.e., in case of a module, the path can be changed also without unmounting/remounting the module).

This subsystem shall work in the following way. Let us suppose that the initial path is `/mnt/dir-A/`. All files in that folder, and in *any* subfolder of that path can be opened using sessions. The way according to which the user tells the subsystem that a file shall be opened using sessions is left as a design choice to the student. 

Once a file is opened using session, userspace applications are allowed to run traditional VFS-related syscalls on them. Anyhow, a new *incarnation* of its content is created, which is initialized with the currently-available content of the original file in `/mnt/dir-A/`. Updates to the file opened using sessions are not immediately visibile in the original file in `/mnt/dir-A/`. Rather, the updates in one incarnation are flushed to the original file only once a session is closed by relying on the `close()` syscall.

When a file is opened using sessions and an incarnation of its content is created, the content needs to be initialized atomically with respect to the closure of another incarnation of the same file (which flushes the content of the session file to the original file). The same is true for concurrent closures of different incarnations of a same file opened using sessions.

This is the so-called *session-based file access semantic*, as opposed to the classical UNIX semantic where any update on a file performed in an I/O session is made visible to other I/O sessions on the same file.

When closing a file opened using session, if the original file has been removed, the closing process must receive `SIGPIPE`. Opening a file which does not exist must make the `open()` syscall fail, obviously.

The subsystem must be designed to support working with a large number of files and a large number of sessions. Moreover, the files can be of any size. Therefore, it is not possible to have only a RAM-backed subsystem. It is left as a design strategy how to use disk-storage to back the various file sessions.

Files opened using sessions must support at least the following set of file operations:

- `open`
- `release`
- `read`
- `write`
- `llseek`

Concurrent I/O sessions on files must be allowed, as well as concurrent operations on a same I/O session, as usual for files in Linux. Atomicity of the concurrent operations must still be guaranteed.

If the path for the files accessed using sessions is changed, open sessions must still be managed according to the session-based semantic. This means that any `open()` on the old path will be served using the classical UNIX semantic after the path change, but files which were already opened will still use the session-based semantic.

At any time, userspace applications can query the subsystem to know:

* The total number of opened sessions
* The number of opened sessions for each file and a list of process names and pids which are currently using sessions (in no particular order).

This information can be provided through `procFS` or `sysFS`, at the discretion of the student.

## How to carry out the work

We are using [GitHub Classroom](https://classroom.github.com/) this year. This is also an opportunity to experiment with the git Version Control System.

Follow this **[<u>INVITATION LINK</u>](https://classroom.github.com/a/j0yfI-y4)** to create a new repo on GitHub, in which you will be carrying out the development work.

If you want to get the best from this experience, remember that git is just a tool. Although it helps you at keeping the work organized, if you use it wrong, you will mess everything up in any case.

Refer to the Git Usage document in the repository to find out some rules which I strongly encourage to follow, when developing collaboratively. In the case of this project, if you follow a *branch-based model*, **you can mention me**  (@alessandropellegrini) **on GitHub when you create a pull request**, to ask for intermediate help remotely (please, don't abuse of this possibility!).

## Deadline to complete the project

As mentioned, there is **one year period** after the end of the classes to complete the project. This means that all projects should be completed by end of June, 2020. After that date, the system will freeze all repositories, and you will be given a mark on what is found in the last commit on `master`.

## What to hand over

To discuss the final project and get the final mark, the students are supposed to provide to the lecturer:

- The implementation of the subsystem
- The implementation of a userspace test application
- The documentation of the code, realized according to the provided template (it is in the `doc/` subfolder of the repo which will be created, you can decide to switch to a wiki or just provide the final documentation in that folder). You are also encouraged to use an automatic documentation system (doxygen or similar). If you do so, please provide also the output generated by this tools.

<u>No printed copy of anything should be carried at the discussion</u>. To discuss the final project, simply send an email to the instructor pointing to the repository where the code and the documentation is provided ***at least <u>one week before</u> any office hours***. Then, come to the office hours for the discussion.

## What will be considered for the mark

Several different aspects will be considered to give the final mark on the project:

* adherence to the specification of the proposed implementation; 
* quality of code;
* performance and correctness of the code;
* clarity and quality of the associated documentation;
* good usage of git.