/*
============================================================================
Name : 3.c
Author : Soumik Pal
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int fd = creat("fileq2", S_IRWXU);
	if(fd < 0)
	{
		perror("File creation failed");
		exit(0);
	}
	printf("FIle descriptor value returned is = %d\n",fd);
}

/*
========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 3.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
FIle descriptor value returned is = 3

=======================================================================
*/
