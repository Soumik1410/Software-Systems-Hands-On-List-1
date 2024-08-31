/*
============================================================================
Name : 10.c
Author : Soumik Pal
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
	char buffer[10]="HelloWorld";
	int fd = open("fileq10", O_RDWR | O_CREAT | O_EXCL);
	write(fd, buffer, 10);
	int retval = lseek(fd, 10, SEEK_CUR);
	if(retval == -1)
	{
		perror("Error in lseek call");
		exit(0);
	}
	printf("lseek return value = %d\n",retval);
	write(fd, buffer, 10);
}

/*
============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 10.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
lseek return value = 20
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ od fileq10
od: fileq10: Permission denied
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ sudo od fileq10
[sudo] password for soumik:
0000000 062510 066154 053557 071157 062154 000000 000000 000000
0000020 000000 000000 062510 066154 053557 071157 062154
0000036
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ sudo od -c fileq10
0000000   H   e   l   l   o   W   o   r   l   d  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   H   e   l   l   o   W   o   r   l   d
0000036

===========================================================================
*/
