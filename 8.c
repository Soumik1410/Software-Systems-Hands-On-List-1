/*
============================================================================
Name : 8.c
Author : Soumik Pal
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	FILE *fp = fopen("fileq8","r");
	if(fp == NULL)
	{
		perror("File opening failed");
		exit(0);
	}
	int c = fgetc(fp);
	char buffer[1024];
	int k=0;
	while(c!=EOF)
	{
		while(c!='\n')
		{
			buffer[k]=c;
			k++;
			c = fgetc(fp);
		}
		buffer[k++]='\n';
		write(1, buffer, k);
		k=0;
		buffer[0]='\0';
		c = fgetc(fp);
	}
}

/*
===============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ vim fileq8
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cat fileq8
kbfj
jvdzknkln
kdnllkvjdz
jvdn53456
nvzv654
[]lb[x
vbHUIFB
541113
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 8.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
kbfj
jvdzknkln
kdnllkvjdz
jvdn53456
nvzv654
[]lb[x
vbHUIFB
541113

================================================================================
*/
