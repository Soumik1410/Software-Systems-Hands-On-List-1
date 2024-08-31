/*
============================================================================
Name : 17_increment_ticket.c
Author : Soumik Pal
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

This file is to read the ticket number stored in fileq17 by 17_storeticket.c, increment it
and print it in a write lock.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int main()
{
	int fd = open("fileq17", O_RDWR);
	if(fd < 0)
	{
		perror("Error in opening file where ticket number is stored");
		exit(0);
	}
	
	char ticket[1024];
	
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	printf("Setting lock\n");
	if((fcntl(fd, F_SETLK, &fl)) == -1)
	{
		perror("Error setting lock");
		exit(0);
	}
	
	int size_read = read(fd, ticket, sizeof(ticket));
	if(size_read == -1)
	{
		perror("Error reading ticket number");
		exit(0);
	}
	int ticket_number = (int)strtol(ticket, NULL, 10);
	ticket_number++;
	printf("New ticket number = %d\n",ticket_number);
	memset(ticket, '\0', size_read);
	sprintf(ticket, "%d", ticket_number);
	lseek(fd, 0, SEEK_SET);
	if((write(fd, ticket, size_read)) == -1)
	{
		perror("Error writing new ticket number");
	}
	fcntl(fd, F_SETLK, &fl);
	printf("Unlocked lock\n");
	
	close(fd);
}

/*
=================================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 17_storeticket.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ more fileq17
10000
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 17_increment_ticket.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Setting lock
New ticket number = 10001
Unlocked lock
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ more fileq17
10001
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Setting lock
New ticket number = 10002
Unlocked lock
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ more fileq17
10002

================================================================================
*/
