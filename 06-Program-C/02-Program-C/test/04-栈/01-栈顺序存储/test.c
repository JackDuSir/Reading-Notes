/*************************************************************************
	> File Name: test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 四  3/21 21:24:33 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

typedef struct _Person
{
	char name[64];
	int age;
} Person;

void test()
{
	Stack stack = Init_SeqStack();

	// 创建数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };

	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	while(Size_SeqStack(stack) > 0)
	{
		Person *person = (Person *)Top_SeqStack(stack);
		printf("Name:%s Age:%d\n", person->name, person->age);
		Pop_SeqStack(stack);
	}
	printf("Size:%d\n", Size_SeqStack(stack));

	Destroy_SeqStack(stack);
}

int main()
{
	test();

	return 0;
}
