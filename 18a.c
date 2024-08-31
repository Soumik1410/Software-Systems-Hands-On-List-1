/*
============================================================================
Name : 18a.c
Author : Soumik Pal
Description : Write a program to perform Record locking.
a. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
typedef struct record
{
	char name[100];
	char gender[2];
	char age[4];
}rec;
int main()
{
	rec r[3]={{"Soumik", "M", "27" },{"Poulami", "F", "27"},{"Saikat", "M", "26"}};

	int fd = open("fileq18", O_WRONLY | O_CREAT, S_IRWXU);
	if(fd < 0)
	{
		perror("Error opening file for writing");
		exit(0);
	}
	int i=0;
	while(i<3)
	{
		char buffer[1024];
                sprintf(buffer, "%s\t%s\t%s\n", r[i].name, r[i].gender, r[i].age);
                int size=strlen(buffer);
		//printf("%d\n",size);
		
		printf("Locking %lu bytes for writing Record %d\n",sizeof(rec),i+1);
		struct flock fl;
		fl.l_type=F_WRLCK;
		fl.l_whence=SEEK_SET;
		fl.l_start = i*sizeof(rec);
		fl.l_len = sizeof(rec);
		fl.l_pid = getpid();
		fcntl(fd, F_SETLK, &fl);

		lseek(fd, i*sizeof(rec), SEEK_SET);
		write(fd, buffer, size);

		fcntl(fd, F_SETLK, &fl);
		printf("Unlocking Record %d\n",i+1);
		
		i++;
	}
}

/*
=============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 18a.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Locking 106 bytes for writing Record 1
Unlocking Record 1
Locking 106 bytes for writing Record 2
Unlocking Record 2
Locking 106 bytes for writing Record 3
Unlocking Record 3
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq18
Soumik	M	27
Poulami	F	27
Saikat	M	26

=============================================================================
*/
