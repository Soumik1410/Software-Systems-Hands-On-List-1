/*
============================================================================
Name : 17_storeticket.c
Author : Soumik Pal
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

This file is the program to store a ticket number and exit.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int fd = open("fileq17", O_WRONLY | O_CREAT | O_EXCL, S_IRWXU);
	if(fd < 0)
	{
		perror("Error creating file to store ticket in");
		exit(0);
	}
	char ticket[5]="10000";
	write(fd, ticket, 5);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 17_storeticket.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ more fileq17
10000

============================================================================
*/
