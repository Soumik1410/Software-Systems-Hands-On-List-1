/*
============================================================================
Name : 30.c
Author : Soumik Pal
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/time.h>
#include<signal.h>
void timer_handler(int signum)
{
	//printf("hello\n");
	if((execl("/bin/date","/bin/date",NULL)) == -1)
		perror("Error in exec call");
}
int main()
{
	int retval=daemon(0,1);
	if(retval == -1)
	{
		perror("Error creating daemon process");
		exit(0);
	}
	
	printf("Created daemon process, it will execute date command after 10 seconds\n");
	struct itimerval timer;
	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=0;
	if((signal(SIGALRM, timer_handler)) == SIG_ERR)
		perror("Error setting signal handler");
	if((setitimer(ITIMER_REAL, &timer, NULL)) == -1)
		perror("Error setting itimer");
	while(1)
	{
		;
	}
}

/*
=====================================================================================

Program Output : 

oumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 30.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Created daemon process, it will execute date command after 10 seconds
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ Sat Aug 31 05:57:34 PM IST 2024

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ 

====================================================================================
*/
