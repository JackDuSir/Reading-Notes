#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mydll.h"

#pragma comment(lib,"./testDll.lib")



void fun(int a){

	if (a == 1){
		printf("a = %d\n", a);
		return; //中断函数很重要
	}

	fun(a - 1);
	printf("a = %d\n", a);
}



int main(void){

	fun(2);
	printf("main\n");

	return 0;
}


int main(){

	int a = 10;
	int b = 20;
	int ret = myAdd(a, b);
	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}