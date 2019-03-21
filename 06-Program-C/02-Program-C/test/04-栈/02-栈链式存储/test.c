/*************************************************************************
	> File Name: test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 四  3/21 21:24:33 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list_stack.h"

typedef struct _Person
{
	StackNode next;
	char name[64];
	int age;
} Person;

void test()
{
	ListStack stack = Init_ListStack();

	// 创建数据
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p4 = { NULL, "ddd", 40 };
	Person p5 = { NULL, "eee", 50 };

	Push_ListStack(stack, &p1);
	Push_ListStack(stack, &p2);
	Push_ListStack(stack, &p3);
	Push_ListStack(stack, &p4);
	Push_ListStack(stack, &p5);

	while(Size_ListStack(stack) > 0)
	{
		Person *person = (Person *)Top_ListStack(stack);
		printf("Name:%s Age:%d\n", person->name, person->age);
		Pop_ListStack(stack);
	}
	printf("Size:%d\n", Size_ListStack(stack));

	Destroy_ListStack(stack);
}

int main()
{
	test();

	return 0;
}
