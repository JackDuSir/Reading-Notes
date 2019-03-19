#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"

int number = 0;

void reversPrint(char *p)
{
	++number;

	//1. 首先要退出递归退出条件
	if (*p == '\0')
	{
		return;
	}



	reversPrint(p + 1);
	printf("%c",*p);
}

void reversePrintList(struct LinkNode *pCurrent)
{
	if (NULL == pCurrent)
	{
		return;
	}


	reversePrintList(pCurrent->next);
	printf("%d ",pCurrent->data);
}


void test01()
{

	char *s = "abcdefg";
	reversPrint(s);


	printf("number:%d\n", number);
}

//链表逆序打印
void test02()
{
	//初始化链表
	struct LinkNode *header = Init_LinkList();

	//链表逆序打印
	reversePrintList(header->next);
	printf("\n");
	Foreach_LinkList(header);

	printf("\n");
	//销毁链表
	Destroy_LinkList(header);

}

int main(){



	test02();


	system("pause");
	return EXIT_SUCCESS;
}