/*
============================================================================
Name : 28.c
Author : Soumik Pal
Description : Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
int main()
{
	printf("FIFO Policy Max priority = %d\n", sched_get_priority_max(SCHED_FIFO));
	printf("FIFO Policy Min priority = %d\n", sched_get_priority_min(SCHED_FIFO));
	printf("RR Policy Max priority = %d\n", sched_get_priority_max(SCHED_RR));
	printf("RR Policy Min priority = %d\n", sched_get_priority_min(SCHED_RR));
	printf("Other Policy Max Priority = %d\n", sched_get_priority_max(SCHED_OTHER));
	printf("Other Policy Min Priority = %d\n", sched_get_priority_min(SCHED_OTHER));

}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 28.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
FIFO Policy Max priority = 99
FIFO Policy Min priority = 1
RR Policy Max priority = 99
RR Policy Min priority = 1
Other Policy Max Priority = 0
Other Policy Min Priority = 0

============================================================================
*/
