/*
============================================================================
Name : 14.c
Author : Soumik Pal
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	struct stat information;
	int retval = lstat(argv[1], &information);
	if(retval == -1)
	{
		perror("Error during stat call");
		exit(0);
	}
	int x = S_ISDIR(information.st_mode);
	if(x != 0)
	{
		printf("File is a directory\n");
		exit(0);
	}
	x = S_ISCHR(information.st_mode);
	if(x != 0)
	{
		printf("File is a character device file\n");
		exit(0);
	}
	x = S_ISBLK(information.st_mode);
	if(x != 0)
	{
		printf("File is a block device file\n");
		exit(0);
	}
	x = S_ISREG(information.st_mode);
	if(x != 0)
	{
		printf("File is a regular file\n");
		exit(0);
	}
	x = S_ISFIFO(information.st_mode);
	if(x != 0)
	{
		printf("File is a FIFO file\n");
		exit(0);
	}
	x = S_ISLNK(information.st_mode);
	if(x != 0)
	{
		printf("File is a symbolic link\n");
		exit(0);
	}
	x = S_ISSOCK(information.st_mode);
	if(x != 0)
	{
		printf("File is a socket\n");
		exit(0);
	}
}

/*
==================================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 14.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out fileq12
File is a regular file
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out /dev/tty0
File is a character device file
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out /dev/sda1
File is a block device file
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out /
File is a directory
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out namedpipefile
Error during stat call: No such file or directory
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out namedpipefile1
File is a FIFO file
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out symlink1
File is a symbolic link

=================================================================================
*/
