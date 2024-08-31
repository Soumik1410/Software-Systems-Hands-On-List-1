/*
============================================================================
Name : 13.c
Author : Soumik Pal
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/select.h>
int main()
{
	struct timeval tv;
	tv.tv_sec=10;
	tv.tv_usec=0;

	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	int retval = select(1, &rfds, NULL, NULL, &tv);
	char buffer[10];
	if(retval == -1)
	{
		perror("Error when waiting on fd to be ready with select");
		exit(0);
	}
	if(retval == 0)
	{
		printf("Data was not available in 10 seconds\n");
		exit(0);
	}
	int size_read = read(0, buffer, 10);
	printf("Data was avaialable in 10 seconds\nThe data input was : \n");
	write(1, buffer, size_read);
}

/*
==========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 13.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
hello
Data was avaialable in 10 seconds
The data input was :
hello
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Data was not available in 10 seconds

==========================================================================
*/
