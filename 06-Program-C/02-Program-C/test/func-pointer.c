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

// 1. 先定义函数类型，通过类型定义指针
void test1()
{
	typedef void(FUNC_TYPE)(int, int);
	FUNC_TYPE *f = my_func;

	f(10,20);
}

// 2. 定义函数指针类型
void test2()
{
	typedef void(*FUNC_POINTER)(int, int);

	FUNC_POINTER f = my_func;

	f(11, 22);
}

// 3. 直接定义函数指针变量
void test3()
{
	int(*f)(int, int) = my_func;

	f(55, 66);
}


// 回调函数
int max(int x, int y)
{
	return x > y? x:y;
}

void test_max_num()
{
	int(*p)(int, int) = &max;	// & 可以省略
	int a, b, c, d;

	printf("请输入三个数字: ");
	scanf("%d %d %d", &a, &b, &c);

	d = p(p(a, b), c);
	printf("最大的数字是: %d\n", d);
}

int main()
{
	test();
	test1();
	test2();
	test3();

	test_max_num();

	return 0;
}
