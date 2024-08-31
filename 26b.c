/*
============================================================================
Name : 26b.c
Author : Soumik Pal
Description : Write a program to execute an executable program.
b. pass some input to an executable program. (for example execute an executable of $./a.out name.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	char *argv[] = {"printname", "Soumik", NULL};
	char *env[] = {NULL};
	printf("Executing printname executable with \'Soumik\' as command line argument\n");
	int retval = execve("printname", argv, env);
	if(retval == -1)
	{
		perror("Error during exec call");
	}
}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ vim printname.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat printname.c
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	printf("My name is %s\n",argv[1]);
}
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc printname.c -o printname
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ls -l printname
-rwxrwxr-x 1 soumik soumik 15960 Aug 31 09:33 printname
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./printname Roy
My name is Roy

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 26b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
Executing printname executable with 'Soumik' as command line argument
My name is Soumik

============================================================================
*/
