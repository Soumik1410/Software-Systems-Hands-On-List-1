/*
============================================================================
Name : 25.c
Author : Soumik Pal
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int pid1 = fork();
	if(pid1 == -1)
	{
		perror("Error in first fork call");
		exit(0);
	}
	if(pid1 == 0)
	{
		sleep(30);
		printf("Child1 exiting\n");
		exit(0);
	}

	int pid2 = fork();
	if(pid2 == -1)
	{
		perror("Error in second fork call");
		exit(0);
	}
	if(pid2 == 0)
	{
		sleep(45);
		printf("Child2 exiting\n");
		exit(0);
	}

	int pid3 = fork();
	if(pid3 == -1)
	{
		perror("Error in third fork call");
		exit(0);
	}
	if(pid3 == 0)
	{
		sleep(60);
		printf("Child3 exiting\n");
		exit(0);
	}
	
	int wpid;
	if(strcmp(argv[1],"1")==0)
		wpid=pid1;
	else if(strcmp(argv[1],"2")==0)
		wpid=pid2;
	else
		wpid=pid3;

	printf("Parent waiting for Child%s\n",argv[1]);
	waitpid(wpid, NULL, 0);
	printf("Parent exiting now\n");
}	

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 25.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out 1
Parent waiting for Child1
Child1 exiting
Parent exiting now
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ Child2 exiting
Child3 exiting

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out 2
Parent waiting for Child2
Child1 exiting
Child2 exiting
Parent exiting now
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ Child3 exiting

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out 3
Parent waiting for Child3
Child1 exiting
Child2 exiting
Child3 exiting
Parent exiting now
soumik@soumik-VirtualBox:~/SS_HandsOnList1$

===========================================================================
*/
