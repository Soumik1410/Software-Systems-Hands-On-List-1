/*
============================================================================
Name : 7.c
Author : Soumik Pal
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc, char *argv[])
{
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 < 0)
	{
		perror("Opening Source File failed");
		exit(0);
	}
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRWXU);
	if(fd2 < 0)
	{
		perror("Opening Target File failed");
		exit(0);
	}
	char buffer[1024];
	int size_read;
	while((size_read = read(fd1, buffer, sizeof(buffer))) > 0)
		write(fd2, buffer, size_read);
}

/*
===========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ touch fileq7
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ vim fileq7
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq7
bdgjbzj
jdkzbjb
kjvdzb vjkz
\jkdz bjkdb
jkcndkjv
15345xf11bz
24f2bdzohio
jvdbnjdzbj
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 7.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out fileq7 fileq7copy
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq7copy
bdgjbzj
jdkzbjb
kjvdzb vjkz
\jkdz bjkdb
jkcndkjv
15345xf11bz
24f2bdzohio
jvdbnjdzbj

===========================================================================
*/
