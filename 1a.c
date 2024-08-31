/*
============================================================================
Name : 1a.c
Author : Soumik Pal
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
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
	int retval = symlink("fileq1", "symlink2");
	if(retval != 0)
	{
		perror("Symbolic link creation failed");
	}
}

/*
==========================================================================

Program Output :

i)Shell Command : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ln -s fileq1 symlink1
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l fileq1 symlink1 
-rw-rw-r-- 1 soumik soumik 0 Aug 30 20:12 fileq1
lrwxrwxrwx 1 soumik soumik 6 Aug 30 20:15 symlink1 -> fileq1

ii)System Call :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 1a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l fileq1 symlink2
-rw-rw-r-- 1 soumik soumik 0 Aug 30 20:12 fileq1
lrwxrwxrwx 1 soumik soumik 6 Aug 30 20:15 symlink2 -> fileq1

==========================================================================
*/
