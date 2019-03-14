/*************************************************************************
	> File Name: memory-test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月14日 星期四 12时23分08秒
 ************************************************************************/

#include<stdio.h>

static int flag = 0;

void test()
{
	flag = 1;
}

int main()
{
	printf("flag = (%d)\n", flag);
	test();
	printf("flag = (%d)\n", flag);
	return 0;
}
