/*
============================================================================
Name : 11a.c
Author : Soumik Pal
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
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
	int fd = open("fileq11", O_RDWR | O_APPEND);
	if(fd < 0)
	{
		perror("Error opening file");
		exit(0);
	}
	char buffer[1024];
	int size_read = read(fd, buffer, 1024);
	int new_fd = dup(fd);
	write(fd, buffer, size_read);
	write(new_fd, buffer, size_read);
}

/*
=========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ vim fileq11
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq11
HelloWorld
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 11.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq11
HelloWorld
HelloWorld
HelloWorld

========================================================================
*/
