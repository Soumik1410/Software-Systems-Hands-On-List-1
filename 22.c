/*
============================================================================
Name : 22.c
Author : Soumik Pal
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int fd = open("fileq22", O_RDWR | O_CREAT | O_EXCL, S_IRWXU);
	if(fd < 0)
	{
		perror("Error opening file");
		exit(0);
	}
	char buffer[]="Hello World\n";
	int pid = fork();
	if(pid < 0)
	{
		perror("Error in fork call");
		exit(0);
	}
	else
	{
		write(fd, buffer, 12);
	}
}

/*
==============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 22.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq22
Hello World
Hello World

==============================================================================
*/
