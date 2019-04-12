/*************************************************************************
	> File Name: test.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月12日 星期五 12时08分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TEST1 0x02
#define TEST2 0x10

int main(int argc, char *argv[])
{

    short x = TEST1 | TEST2;
    printf("x =%d\n", x);
    printf("TEST1: %s\n", x & TEST1 ? "YES" : "NO");

    return 0;
}

