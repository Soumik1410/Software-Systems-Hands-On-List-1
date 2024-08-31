/*
============================================================================
Name : 19.c
Author : Soumik Pal
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<x86intrin.h>
int main()
{
	unsigned long long start, end;
	start = __rdtsc();
	printf("Pid of process = %d\n",getpid());
	end = __rdtsc();
	printf("Time taken for the call = %llu clock cycles\n", end - start);
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 19.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Pid of process = 11921
Time taken for the call = 5784445 clock cycles

===========================================================================
*/
