/*
============================================================================
Name : 4.c
Author : Soumik Pal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int fd = open("fileq4", O_RDWR | O_CREAT);
	if(fd < 0)
	{
		perror("File opening without O_EXCL failed");
	}
	else
	{
		printf("File opening without O_EXCL successful\n");
	}
	fd = open("fileq2", O_RDWR | O_CREAT | O_EXCL);
	if(fd < 0)
	{
		perror("File opening with O_EXCL failed as expected");
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 4.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
File opening without O_EXCL successful
File opening with O_EXCL failed as expected: File exists

===========================================================================
*/
