/*
============================================================================
Name : 1b.c
Author : Soumik Pal
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
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
	int retval = link("fileq1", "hardlink2");
	if(retval != 0)
	{
		perror("Hard link creation failed");
	}
}

/*
=========================================================================

Program Output : 

i) Shell Command : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ln fileq1 hardlink1
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l fileq1 hardlink1 
-rw-rw-r-- 2 soumik soumik 0 Aug 30 20:12 fileq1
-rw-rw-r-- 2 soumik soumik 0 Aug 30 20:12 hardlink1

ii) System Call :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 1b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l fileq1 hardlink2
-rw-rw-r-- 3 soumik soumik 0 Aug 30 20:12 fileq1
-rw-rw-r-- 3 soumik soumik 0 Aug 30 20:12 hardlink2

========================================================================
*/
