/*
============================================================================
Name : 6.c
Author : Soumik Pal
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	char buffer[32];
	int size_read = read(0, buffer, 32);
	fflush(stdout);
	write(1, buffer, size_read);
	fflush(stdout);
}

/*
=========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 6.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
hello
hellosoumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$

==========================================================================
*/
