/*
============================================================================
Name : 21.c
Author : Soumik Pal
Description : Write a program, call fork and print the parent and child process id.
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
		printf("Parent PID : %d\n",getpid());
		printf("Child PID : %d\n",pid);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 21.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Parent PID : 12059
Child PID : 12060

===========================================================================
*/
