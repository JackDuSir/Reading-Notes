/*************************************************************************
	> File Name: linknode.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月20日 星期三 17时11分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _LinkNode
{
	struct _LinkNode *next;
}LinkNode;

typedef struct _Person
{
	LinkNode *node;
	char name[64];
	int age;
}Person;

void test()
{
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p4 = { NULL, "ddd", 40 };
	Person p5 = { NULL, "eee", 50 };

	LinkNode *pp1 = (LinkNode *)&p1;
	LinkNode *pp2 = (LinkNode *)&p2;
	LinkNode *pp3 = (LinkNode *)&p3;
	LinkNode *pp4 = (LinkNode *)&p4;
	LinkNode *pp5 = (LinkNode *)&p5;

	pp1->next = pp2;
	pp2->next = pp3;
	pp3->next = pp4;
	pp4->next = pp5;
	pp5->next = NULL;

	LinkNode *pCurrent = pp1;
	while(pCurrent != NULL)
	{
		Person *person = (Person *)pCurrent;
		printf("Name=%s Age=%d\n", person->name, person->age);

		pCurrent = pCurrent->next;
	}
}

int main()
{
	test();

	return 0;
}

