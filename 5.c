/*
============================================================================
Name : 5.c
Author : Soumik Pal
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
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
	int fd1 = open("fileq5a", O_RDWR | O_CREAT);
	int fd2 = open("fileq5b", O_RDWR | O_CREAT);
	int fd3 = open("fileq5c", O_RDWR | O_CREAT);
	int fd4 = open("fileq5d", O_RDWR | O_CREAT);
	int fd5 = open("fileq5e", O_RDWR | O_CREAT);
	while(1);
}

/*
===========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 5.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out &
[1] 7667
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cd /proc/7667/fd
soumik@soumik-VirtualBox:/proc/7667/fd$ ls -lrt
total 0
lrwx------ 1 soumik soumik 64 Aug 30 20:58 7 -> /home/soumik/SS_HandsOnList1/fileq5e
lrwx------ 1 soumik soumik 64 Aug 30 20:58 6 -> /home/soumik/SS_HandsOnList1/fileq5d
lrwx------ 1 soumik soumik 64 Aug 30 20:58 5 -> /home/soumik/SS_HandsOnList1/fileq5c
lrwx------ 1 soumik soumik 64 Aug 30 20:58 4 -> /home/soumik/SS_HandsOnList1/fileq5b
lrwx------ 1 soumik soumik 64 Aug 30 20:58 3 -> /home/soumik/SS_HandsOnList1/fileq5a
lrwx------ 1 soumik soumik 64 Aug 30 20:58 2 -> /dev/pts/0
lrwx------ 1 soumik soumik 64 Aug 30 20:58 1 -> /dev/pts/0
lrwx------ 1 soumik soumik 64 Aug 30 20:58 0 -> /dev/pts/0

===========================================================================
*/

