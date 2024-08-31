/*
============================================================================
Name : 29.c
Author : Soumik Pal
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR)
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
#include<errno.h>
int main()
{
	struct sched_param param;
	param.sched_priority = 99;
	int pid = getpid();
	char pidstr[1024];
	sprintf(pidstr, "%d", pid);
	
	int cpid1 = fork();
	if(cpid1 == 0)
	{
		if((execl("/bin/chrt","/bin/chrt","-p",pidstr,NULL) == -1))
			perror("Error");
	}
	sleep(5);
	
	printf("Setting current process to FIFO scheduling policy\n");
	int retval=sched_setscheduler(0, SCHED_FIFO, &param);
	if(retval == -1)
	{
		perror("Error");
	}

	int cpid2 = fork();
	if(cpid2 == 0)
	{
		if((execl("/bin/chrt","/bin/chrt","-p",pidstr,NULL) == -1))
			perror("Error");
	}
	sleep(5);

	printf("Setting current process to RR scheduling policy\n");
        retval=sched_setscheduler(0, SCHED_RR, &param);
        if(retval == -1)
        {
                perror("Error");
        }

        int cpid3 = fork();
        if(cpid3 == 0)
        {
                if((execl("/bin/chrt","/bin/chrt","-p",pidstr,NULL) == -1))
                        perror("Error");
        }
        sleep(5);
	
}

/*
==========================================================================================

Program Output : (Needed to be compiled & run as root, otherwise set_scheduler was failing on my system)

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 29.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ sudo su
root@soumik-VirtualBox:/home/soumik/SS_HandsOnList1# cc 29.c 
root@soumik-VirtualBox:/home/soumik/SS_HandsOnList1# ./a.out
pid 16007's current scheduling policy: SCHED_OTHER
pid 16007's current scheduling priority: 0
Setting current process to FIFO scheduling policy
pid 16007's current scheduling policy: SCHED_FIFO
pid 16007's current scheduling priority: 99
Setting current process to RR scheduling policy
pid 16007's current scheduling policy: SCHED_RR
pid 16007's current scheduling priority: 99

===========================================================================================
*/
