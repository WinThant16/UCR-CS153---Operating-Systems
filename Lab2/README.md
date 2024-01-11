Lab 2: Scheduler
====================
--------------------
1. Getting Started
--------------------

Download a new directory of starter code of XV6 for Lab2 from this
`link <https://github.com/mit-pdos/xv6-public>`_.

To get started, look at the file ``proc.c``.

--------------------
2. Assignment (95%)
--------------------

In this part of the assignment, you will change the scheduler from
a simple round-robin to a priority scheduler.  Add a priority value to
each process (lets say taking a range between 0 to 31).  The range
does not matter, it is just a proof of concept.  When scheduling from
the ready list you will always schedule the highest priority
thread/process first.  All the processes should have a default initial
priority of 10.

Add a system call to change the priority of a process.  A process can
change its priority at any time.  If the priority becomes lower than
any process on the ready list, you must switch to that process.

**Goals**: Understand how the scheduler works.  Understand how
to implement a scheduling policy and characterize its impact on
performance.  Understand priority inversion and a possible solution
for it.

----------------------------
3. Bonus Section (upto 10%)
----------------------------

Implement up to two of the next three items.  Each is a 5% bonus.
To get credit for a bonus part, you must also develop a user test that
will illustrate it.

* To avoid starvation, implement aging of priority.  If a process
  waits increase its priority.  When it runs, decrease it.
  (Possible Bonus 1)

  |ep|

* Implement priority donation/priority inheritance. (Possible Bonus 2)

  |ep|

* Add fields to track the scheduling performance of each process.
  These values should allow you to compute the turnaround time and
  wait time for each process.  Add a system call to extract these
  values or alternatively print them out when the process exits.
  (Possible Bonus 3)

--------------------------------------
4. Questions to Explore
--------------------------------------

* Explain how the current scheduler works, including interaction with
  the timer.

--------------------------------------

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/YIyVslbD)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=12667958)


NOTE: we have stopped maintaining the x86 version of xv6, and switched
our efforts to the RISC-V version
(https://github.com/mit-pdos/xv6-riscv.git)

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also https://pdos.csail.mit.edu/6.828/, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Anton Burtsev, Cody Cutler, Mike CAT, Tej Chajed, eyalz800,
Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron,Shivam Handa, Bryan Henry, Jim Huang, Alexander
Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller, Eddie Kohler, Austin
Liew, Imbar Marinescu, Yandong Mao, Matan Shabtay, Hitoshi Mitake, Carmi
Merimovich, Mark Morrissey, mtasm, Joel Nider, Greg Price, Ayan Shafqat,
Eldar Sehayek, Yongming Shen, Cam Tenny, tyfkda, Rafael Ubal, Warren
Toomey, Stephen Tu, Pablo Ventura, Xi Wang, Keiichi Watanabe, Nicolas
Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2018 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

We don't process error reports (see note on top of this file).

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run
"make". On non-x86 or non-ELF machines (like OS X, even on x86), you
will need to install a cross-compiler gcc suite capable of producing
x86 ELF binaries (see https://pdos.csail.mit.edu/6.828/).
Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC
simulator and run "make qemu".
