#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mylib.h"

int main(){

	int a = 10;
	int b = 20;

	int ret = myAdd(a, b);

	printf("ret = %d\n", ret);


	system("pause");
	return EXIT_SUCCESS;
}