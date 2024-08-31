/*
============================================================================
Name : 24.c
Author : Soumik Pal
Description : Write a program to create an orphan process.
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
	if(pid == -1)
	{
		perror("Error in fork call");
		exit(0);
	}
	else if(pid > 0)
	{
		printf("Parent with pid %d going to sleep for 10 seonds\n",getpid());
		sleep(10);
		printf("Parent with pid %d exiting before child has terminated\n", getpid());
		exit(0);
	}
	else
	{
		printf("Child with pid %d and parent pid %d going to sleep for 30 seconds, to become an orphan after parent exits in 10 seconds\n", getpid(), getppid());
		sleep(30);
		printf("Child is now an orphan process, its parent pid is now %d\n", getppid());
	      	exit(0);
	}
}

/*
==========================================================================

Program Output :

oumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 24.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Parent with pid 12574 going to sleep for 10 seonds
Child with pid 12575 and parent pid 12574 going to sleep for 30 seconds, to become an orphan after parent exits in 10 seconds
Parent with pid 12574 exiting before child has terminated
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ Child is now an orphan process, its parent pid is now 2659

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ps -l 2659
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY        TIME CMD
4 S  1000    2659       1  0  80   0 -  5309 -      ?          0:03 /usr/lib/systemd/systemd --user

=========================================================================
*/
