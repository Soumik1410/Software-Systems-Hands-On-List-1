/*
============================================================================
Name : 20.c
Author : Soumik Pal
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	while(1);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 20.c
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out &
[2] 11997
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ps -l 11997
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY        TIME CMD
0 R  1000   11997    6622 99  80   0 -   637 -      pts/0      0:12 ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ kill -9 11997
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
[2]+  Killed                  ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ nice -n 5 ./a.out &
[2] 11999
soumik@soumik-VirtualBox:~/SS_HandsOnList1$
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ps -l 11999
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY        TIME CMD
0 R  1000   11999    6622 99  85   5 -   637 -      pts/0      0:05 ./a.out

===========================================================================
*/
