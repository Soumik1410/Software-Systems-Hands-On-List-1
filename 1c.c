/*
============================================================================
Name : 1c.c
Author : Soumik Pal
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int retval = mkfifo("namedpipefile2", S_IRWXU);
	if(retval != 0)
	{
		perror("Named Pipe file creation failed");
	}
}

/*
===========================================================================

Program Output :

i) Shell Command :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ mkfifo namedpipefile1
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l namedpipefile1 
prw-rw-r-- 1 soumik soumik 0 Aug 30 20:23 namedpipefile1

ii) System Call :

oumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 1c.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l namedpipefile2
prwx------ 1 soumik soumik 0 Aug 30 20:33 namedpipefile2

===========================================================================
*/
