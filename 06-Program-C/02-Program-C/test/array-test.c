/*************************************************************************
	> File Name: array-test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月15日 星期五 13时00分54秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int *p = arr + 2;
	printf("*p = (%d)\n", *p);
	printf("*p = (%d)\n", p[-1]);
	return 0;
}
