/*
============================================================================
Name : 2.c
Author : Soumik Pal
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
int main()
{
	while(1);
}

/*
=============================================================================

Program Output : 

oumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out &
[1] 7439
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cd /proc/7439/
soumik@soumik-VirtualBox:/proc/7439$ more status
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	7439
Ngid:	0
Pid:	7439
PPid:	6622
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 114 1000
NStgid:	7439
NSpid:	7439
NSpgid:	7439
NSsid:	6622
Kthread:	0
VmPeak:	    2604 kB
VmSize:	    2548 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1024 kB
VmRSS:	    1024 kB
RssAnon:	       0 kB
RssFile:	    1024 kB
RssShmem:	       0 kB
VmData:	      92 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1748 kB
VmPTE:	      40 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
untag_mask:	0xffffffffffffffff
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
voluntary_ctxt_switches:	0
nonvoluntary_ctxt_switches:	83
x86_Thread_features:
x86_Thread_features_locked:

===============================================================================
*/

