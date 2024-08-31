/*
============================================================================
Name : 16a.c
Author : Soumik Pal
Description : Write a program to perform mandatory locking.
a. Implement write lock
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
	int fd = open("fileq16", O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if(fd < 0)
	{
		perror("Error opening file");
		exit(0);
	}
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	
	char buffer[]="Hello World\n";
	fcntl(fd, F_SETLK, &fl);
	printf("File fileq16 locked for writing\n");
	write(fd, buffer, sizeof(buffer));
	sleep(2);
	fcntl(fd, F_SETLK, &fl);
	printf("File fileq16 unlocked\n");
}

/*
==============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 16a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
File fileq16 locked for writing
File fileq16 unlocked
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq16
Hello World

=============================================================================
*/
