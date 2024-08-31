/*
============================================================================
Name : 18b.c
Author : Soumik Pal
Description : Write a program to perform Record locking.
b. Implement read lock
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
	rec r;
	
	int fd = open("fileq18", O_RDONLY);
	if(fd < 0)
	{
		perror("Error opening file for writing");
		exit(0);
	}
	int i=0;
	while(i<3)
	{
		char buffer[1024];
		
		printf("Locking Record %d\n",i+1);
		struct flock fl;
		fl.l_type=F_RDLCK;
		fl.l_whence=SEEK_SET;
		fl.l_start = i*sizeof(rec);
		fl.l_len = sizeof(rec);
		fl.l_pid = getpid();
		fcntl(fd, F_SETLK, &fl);

		lseek(fd, i*sizeof(rec), SEEK_SET);
		read(fd, buffer, sizeof(rec));

		sscanf(buffer, "%s\t%s\t%s\n", r.name, r.gender, r.age);
		printf("Record %d : Name - %s\tGender - %s\tAge - %s\n", i+1, r.name, r.gender, r.age);
		fcntl(fd, F_SETLK, &fl);
		printf("Unlocking Record %d\n\n",i+1);
		
		i++;
	}
}

/*
=============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 18b.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Locking Record 1
Record 1 : Name - Soumik	Gender - M	Age - 27
Unlocking Record 1

Locking Record 2
Record 2 : Name - Poulami	Gender - F	Age - 27
Unlocking Record 2

Locking Record 3
Record 3 : Name - Saikat	Gender - M	Age - 26
Unlocking Record 3


=============================================================================
*/

