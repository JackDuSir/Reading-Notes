/*************************************************************************
	> File Name: LinkNode.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月20日 星期三 17时41分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 节点指针域定义
typedef struct _LinkNode LinkNode;
struct _LinkNode
{
	LinkNode *next;
};

// 头节点定义
typedef struct _LinkList
{
	LinkNode head;	// 头结点
	int size;
} LinkList;

typedef void * LK;		// 不希望看到内部数据是可以这么定义

// 初始化链表
LK init_LinkList()
{
	LinkList *list = malloc(sizeof(LinkList));
	if (NULL == list)
		return NULL;

	list->head.next = NULL;
	list->size = 0;
	
	return list;
}

// 插入节点
void Insert_LinkList(LK list, int position, void *data)
{
	if (NULL == list || NULL == data)
		return;

	LinkList *mylist = (LinkList *)list;
	LinkNode *mynode = (LinkNode *)data;

	if (position < 0 || position > mylist->size)
		position = mylist->size;

	// 找位置（找到position位置的前一个位置）
	LinkNode *pCurrent = &(mylist->head);
	int i = 0;
	for (i; i < position; i++)
		pCurrent = pCurrent->next;

	// 数据入链表
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;

	mylist->size++;
	//printf("%s %d\n", __FUNCTION__, __LINE__);
}

// 遍历
void Foreach_LinkList(LK list, void(*myforeach)(void *))
{
	if (NULL == list || NULL == myforeach)
		return;

	LinkList *mylist = (LinkList *)list;
	LinkNode *pCurrent = mylist->head.next;  // ?
	while(pCurrent)
	{
		myforeach(pCurrent);
		pCurrent = pCurrent->next;
	}
	//printf("%s %d\n", __FUNCTION__, __LINE__);
}

// 删除节点
void RemoveByPos_LinkList(LK list, int position)
{
	if (NULL == list)
		return;

	LinkList *mylist = (LinkList *)list;
	if (position < 0 || position > mylist->size -1)
		return;

	// 辅助指针
	LinkNode *pCurrent = &(mylist->head);
	int i = 0;
	for (i; i < position; i++)
		pCurrent = pCurrent->next;

	// 缓存下待删除节点
	LinkNode *pDel = pCurrent->next;

	// 重新建立待删除节点的前驱和后继节点关系
	pCurrent->next = pDel->next;

	mylist->size--;
}

// 销毁
void Destroy_LinkList(LK list)
{
	if (NULL == list)
		return;

	free(list);
	list = NULL;
}

typedef struct _Person
{
	LinkNode node;	// 结构体应该是指针？单向链表没问题，但是双向链表保存的应该是8个字节，指针的话会丢掉数据
	char name[64];
	int age;
} Person;

void myPrint(void *data)
{
	Person *person = (Person *)data;
	printf("Name=%s Age=%d\n", person->name, person->age);
}

void test()
{
	// 初始化链表
	LK list = init_LinkList();

	// 创建数据
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p4 = { NULL, "ddd", 40 };
	Person p5 = { NULL, "eee", 50 };

	// 插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	// 遍历
	Foreach_LinkList(list, myPrint);

	// 删除
	RemoveByPos_LinkList(list, 1);
	printf("---------------------------------\n");

	// 遍历
	Foreach_LinkList(list, myPrint);

	// 销毁
	Destroy_LinkList(list);
}

int main()
{
	test();

	return 0;
}
