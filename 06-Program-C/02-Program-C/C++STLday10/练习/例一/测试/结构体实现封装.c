#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{

	int a;
	int b;
	int(*p)(int a,int b);



};
int get(int a, int b)
{
	int c = a;
	int d = b;
	return c + d;
}


void test()
{
	struct Person p1;
	p1.p = get;
	int i=p1.p(1,2);
	printf("%d", i);
	//printf("%d", p1.a);
}



int main()
{

	test();

	system("pause");

}