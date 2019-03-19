#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//链表节点数据结构
struct LinkNode
{
	struct LinkNode *next;
};


//链表结构体
struct LList
{
	struct LinkNode header; //头结点
	int size;
};

typedef void * LinkList;


//初始化链表
LinkList Init_LinkList()
{

	struct LList *list = malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}

	list->header.next = NULL;
	list->size = 0;

	return list;
}


void Insert_LinkList(LinkList list, int position, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;
	struct LinkNode *mynode = (struct LinkNode *)data;


	if (position < 0 || position > mylist->size)
	{
		position = mylist->size;
	}


	//找位置(找到position位置的前一个位置)
	struct LinkNode *pCurrent = &(mylist->header); 
	for (int i = 0; i < position; ++i)
	{
		pCurrent = pCurrent->next;
	}


	//数据入链表
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;


	mylist->size++;
}


void Foreach_LinkList(LinkList list, void(*myforeach)(void *) )
{

	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;

	struct LinkNode *pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		
		myforeach(pCurrent);
		pCurrent = pCurrent->next;
	}

}


struct Person
{
	struct LinkNode node; //结构体应该指针？
	char name[64];
	int age;
};

void myPrint(void *data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name,person->age);
}

void test()
{

	//初始化链表
	LinkList list = Init_LinkList();


	//创建数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };
	struct Person p6 = { NULL, "fff", 60 };


	//插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);


	//遍历
	Foreach_LinkList(list, myPrint);


}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}