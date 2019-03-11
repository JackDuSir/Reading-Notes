/*************************************************************************
	> File Name: 01-pointer.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月11日 星期一 16时13分21秒
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	char str[] = "hello world";
	char *p = str;
	*p = 'm';
	p++;
	*p = 'i';
	printf("str = %s\n", str);

	p = "mike jiang";
	printf("p = %s\n", p);

	char *q = "test";
	printf("q = %s\n", q);
	return 0;
}
