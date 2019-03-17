/*************************************************************************
	> File Name: func-pointer.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 日  3/17 16:18:42 2019
 ************************************************************************/

#include<stdio.h>

typedef void(p)(int, int);

void my_func(int x, int y)
{
	printf("x=(%d) y=(%d)\n", x, y);
}

void test()
{
	p *p1 = my_func;
	p1(2,3);
}

int main()
{
	test();
	return 0;
}
