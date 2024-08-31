/*
============================================================================
Name : 9.c
Author : Soumik Pal
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/sysmacros.h>
#include<time.h>
int main()
{
	struct stat information;
	int retval = stat("fileq9", &information);
	if(retval == -1)
	{
		perror("Error getting stats of file");
		exit(0);
	}
	printf("Inode = %lu\n", information.st_ino);
	printf("Number of Hard Links = %lu\n", information.st_nlink);
	printf("UID = %d\n", information.st_uid);
	printf("GID = %d\n", information.st_gid);
	printf("Size = %ld\n", information.st_size);
	printf("Block size = %ld\n", information.st_blksize);
	printf("Number of blocks = %ld\n", information.st_blocks);
	printf("Time of last access = %s",ctime((const time_t *)&information.st_atim));
	printf("Time of last modification = %s",ctime((const time_t *)&information.st_mtim));
	printf("Time of last change = %s",ctime((const time_t *)&information.st_ctim));
}

/*
============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 9.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Inode = 657608
Number of Hard Links = 1
UID = 1000
GID = 1000
Size = 91
Block size = 4096
Number of blocks = 8
Time of last access = Fri Aug 30 21:49:38 2024
Time of last modification = Fri Aug 30 21:49:38 2024
Time of last change = Fri Aug 30 21:49:38 2024

===========================================================================
*/
