/*
============================================================================
Name : 26a.c
Author : Soumik Pal
Description : Write a program to execute an executable program.
a. use some executable program
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	char *argv[]={"helloworld", NULL};
	char *env[]={NULL};
	printf("Executing helloworld executable\n");
	int retval = execve("helloworld",argv,env);
	if(retval == -1)
	{
		perror("Error during execve");
	}
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ vim helloworld.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat helloworld.c
#include<stdio.h>
int main()
{
	printf("Hello World\n");
}
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc helloworld.c -o helloworld
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 26a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Executing helloworld executable
Hello World

===========================================================================
*/
