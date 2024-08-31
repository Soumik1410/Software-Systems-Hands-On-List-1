/*
============================================================================
Name : 11c.c
Author : Soumik Pal
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
c. use fcntl
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
	if( fd < 0)
	{
		perror("Error opening file");
		exit(0);
	}
	char buffer[1024];
	int size_read = read(fd, buffer, 1024);
	write(fd, buffer, size_read);
	int new_fd = fcntl(fd, F_DUPFD, fd+1);
	write(new_fd, buffer,size_read);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq11
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 11c.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq11
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld
HelloWorld

==========================================================================
*/
