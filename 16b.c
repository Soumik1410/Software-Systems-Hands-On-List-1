/*
============================================================================
Name : 16b.c
Author : Soumik Pal
Description : Write a program to perform mandatory locking.
b. Implement read lock
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
	int fd = open("fileq16", O_RDONLY);
	struct flock fl;
	fl.l_type = F_RDLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	printf("Locking fileq16 for reading\n");
	
	char buffer[1024];
	fcntl(fd, F_SETLK, &fl);
	int size_read=read(fd, buffer, 1024);
	buffer[size_read]='\0';
	size_read++;
	printf("%s",buffer);
	sleep(2);
	fcntl(fd, F_SETLK, &fl);
	printf("File unlocked after reading\n");
}	

/*
==============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 16b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Locking fileq16 for reading
Hello World
File unlocked after reading

==============================================================================
*/
