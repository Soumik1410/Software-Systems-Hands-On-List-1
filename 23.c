/*
============================================================================
Name : 23.c
Author : Soumik Pal
Description : Write a program to create a Zombie state of the running program.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int pid = fork();
	if(pid > 0)
	{
		printf("Parent process with pid %d going to sleep for 60 seconds to create zombie process\n", getpid());
		sleep(60);
	}
	else if(pid == 0)
	{
		printf("Child process with pid %d terminating, while parent is busy, so exit status wont be reaped, so it will become a zombie\n", getpid()); 
		exit(0);
	}
	else
	{
		perror("Error in fork call");
	}
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 23.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out &
[3] 12460
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ Parent process with pid 12460 going to sleep for 60 seconds to create zombie process
Child process with pid 12461 terminating, while parent is busy, so exit status wont be reaped, so it will become a zombie

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ps -l 12461
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY        TIME CMD
1 Z  1000   12461   12460  0  80   0 -     0 -      pts/0      0:00 [a.out] <defunct>
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ more /proc/12461/status
Name:	a.out
State:	Z (zombie)
Tgid:	12461
Ngid:	0
Pid:	12461
PPid:	12460
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	0
Groups:	4 24 27 30 46 100 114 1000
NStgid:	12461
NSpid:	12461
NSpgid:	12460
NSsid:	6622
Kthread:	0
Threads:	1
SigQ:	0/18383
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	vulnerable
SpeculationIndirectBranch:	always enabled
Cpus_allowed:	f
Cpus_allowed_list:	0-3
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000
000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000
,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	1
nonvoluntary_ctxt_switches:	2
x86_Thread_features:
x86_Thread_features_locked:

=================================================================================
*/
