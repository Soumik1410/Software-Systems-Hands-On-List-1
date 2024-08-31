/*
============================================================================
Name : 27d.c
Author : Soumik Pal
Description : Write a program to execute ls -Rl by the following system calls
d. execv
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	char *arg[]={"/bin/ls","-Rl",NULL};
        execv("/bin/ls",arg);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList1$ cc 27d.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList1$ ./a.out
.:
total 216
-rw-rw-r-- 1 soumik soumik  1710 Aug 30 22:23 10.c
-rw-rw-r-- 1 soumik soumik  1258 Aug 30 22:33 11a.c
-rw-rw-r-- 1 soumik soumik  1307 Aug 30 23:20 11b.c
-rw-rw-r-- 1 soumik soumik  1579 Aug 30 23:26 11c.c
-rw-rw-r-- 1 soumik soumik   929 Aug 31 00:09 12.c
-rw-rw-r-- 1 soumik soumik  1474 Aug 31 01:19 13.c
-rw-rw-r-- 1 soumik soumik  2263 Aug 31 01:48 14.c
-rw-rw-r-- 1 soumik soumik  4156 Aug 31 06:27 15.c
-rw-rw-r-- 1 soumik soumik   953 Aug 31 06:44 19.c
-rw-rw-r-- 1 soumik soumik  1345 Aug 30 20:17 1a.c
-rw-rw-r-- 1 soumik soumik  1273 Aug 30 20:22 1b.c
-rw-rw-r-- 1 soumik soumik  1263 Aug 30 20:34 1c.c
-rw-rw-r-- 1 soumik soumik  1403 Aug 31 06:58 20.c
-rw-rw-r-- 1 soumik soumik   820 Aug 31 07:04 21.c
-rw-rw-r-- 1 soumik soumik  1124 Aug 31 07:21 22.c
-rw-rw-r-- 1 soumik soumik  2715 Aug 31 07:38 23.c
-rw-rw-r-- 1 soumik soumik  1772 Aug 31 07:51 24.c
-rw-rw-r-- 1 soumik soumik  2030 Aug 31 08:46 25.c
-rw-rw-r-- 1 soumik soumik  1189 Aug 31 09:22 26a.c
-rw-rw-r-- 1 soumik soumik  1598 Aug 31 09:34 26b.c
-rw-rw-r-- 1 soumik soumik  3646 Aug 31 10:10 27a.c
-rw-rw-r-- 1 soumik soumik  3705 Aug 31 10:13 27b.c
-rw-rw-r-- 1 soumik soumik  3783 Aug 31 10:16 27c.c
-rw-rw-r-- 1 soumik soumik   622 Aug 31 10:19 27d.c
-rw-rw-r-- 1 soumik soumik  2367 Aug 30 20:37 2.c
-rw-rw-r-- 1 soumik soumik   901 Aug 30 20:44 3.c
-rw-rw-r-- 1 soumik soumik  1098 Aug 30 20:50 4.c
-rw-rw-r-- 1 soumik soumik  1741 Aug 30 20:58 5.c
-rw-rw-r-- 1 soumik soumik   930 Aug 30 21:05 6.c
-rw-rw-r-- 1 soumik soumik  1613 Aug 30 21:14 7.c
-rw-rw-r-- 1 soumik soumik  1358 Aug 30 21:28 8.c
-rw-rw-r-- 1 soumik soumik  1926 Aug 30 21:56 9.c
-rwxrwxr-x 1 soumik soumik 16000 Aug 31 10:19 a.out
-rw-rw-r-- 3 soumik soumik     0 Aug 30 20:12 fileq1
--w--wx--T 1 soumik soumik    30 Aug 30 22:21 fileq10
-rw-rw-r-- 1 soumik soumik   297 Aug 30 23:25 fileq11
---S--x--T 1 soumik soumik     0 Aug 31 00:08 fileq12
-rwx------ 1 soumik soumik     0 Aug 30 20:44 fileq2
-rwx------ 1 soumik soumik    24 Aug 31 07:20 fileq22
-r-sr-x--T 1 soumik soumik     0 Aug 30 20:57 fileq5a
---------- 1 soumik soumik     0 Aug 30 20:57 fileq5b
---------- 1 soumik soumik     0 Aug 30 20:57 fileq5c
---------- 1 soumik soumik     0 Aug 30 20:57 fileq5d
---------- 1 soumik soumik     0 Aug 30 20:57 fileq5e
-rw-rw-r-- 1 soumik soumik    84 Aug 30 21:13 fileq7
-rwx------ 1 soumik soumik    84 Aug 30 21:13 fileq7copy
-rw-rw-r-- 1 soumik soumik    66 Aug 30 21:20 fileq8
-rw-rw-r-- 1 soumik soumik    91 Aug 30 21:49 fileq9
-rw-rw-r-- 3 soumik soumik     0 Aug 30 20:12 hardlink1
-rw-rw-r-- 3 soumik soumik     0 Aug 30 20:12 hardlink2
-rwxrwxr-x 1 soumik soumik 15960 Aug 31 09:21 helloworld
-rw-rw-r-- 1 soumik soumik    59 Aug 31 09:13 helloworld.c
prw-rw-r-- 1 soumik soumik     0 Aug 30 20:23 namedpipefile1
prwx------ 1 soumik soumik     0 Aug 30 20:33 namedpipefile2
-rwxrwxr-x 1 soumik soumik 15960 Aug 31 09:33 printname
-rw-rw-r-- 1 soumik soumik   110 Aug 31 09:28 printname.c
lrwxrwxrwx 1 soumik soumik     6 Aug 30 20:15 symlink1 -> fileq1
lrwxrwxrwx 1 soumik soumik     6 Aug 30 20:15 symlink2 -> fileq1

============================================================================
*/
