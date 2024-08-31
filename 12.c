/*
============================================================================
Name : 12.c
Author : Soumik Pal
Description : Write a program to find out the opening mode of a file. Use fcntl.
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
	int fd = open("fileq12", O_RDWR | O_CREAT);
	int open_mode=fcntl(fd, F_GETFL, 0);
	printf("Integer equivalent of opening mode flags received from fcntl = %d\n", open_mode);
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 12.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Integer equivalent of opening mode flags received from fcntl = 32770

===========================================================================
*/
