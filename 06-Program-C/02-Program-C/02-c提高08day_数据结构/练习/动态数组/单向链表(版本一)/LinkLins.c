#include "LinkLins.h"

//节点结构体
struct LinkNode
{
	//data可以指向任何
	void *data;
	//next 指向下一个节点
	struct LinkNode *next;

};
//链表信息结构体
struct LList
{
	//保存头结点的地址
	struct LinkNode header;
	//保存链表的节点
	int size;
};

LinkList Init_LinkList()//初始化链表(用链表结构体)
{	
	//开辟一块内存，
	struct LList *list = malloc(sizeof(struct LList));

	if (NULL == list)
	{
		return NULL;
	}

	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;
	return list;
}

//用链表信息结构体，插入新节点
//首先接收一个void *类型
//pos要插入得位置
void Insert_LinkList(LinkList list, int pos, void *data)//插入节点
{
	if (NULL == data)
	{
		return;
	}

	if (NULL == list)
	{
		return;
	}
	//辅助指针，辅助结构体信息指针
	struct LList *mylist = (struct LList *)list;
	//如果pos<0后或大于最大节点就在最后插入
	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	struct LinkNode * pCurrent = &(mylist->header);

	//循环找到pos之前的节点
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//开辟新的节点把数值传递给他，并把这个节点链接
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//前插
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	//节点增加一个
	mylist->size++;
}

void Foreach_LinkList(LinkList list, FOREACH myforeach)//遍历节点
{
	if (NULL==list)
	{
		return;
	}
	if (NULL == myforeach)
	{
		return;
	}
	//
	struct LList *mylist = (struct LList *)list;

	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent!= NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void RemoveByPos_LinkList(LinkList list, int pos)//按位置删除
{ 
	if (NULL == list)
	{
		return;
	}
	//辅助节点
	struct LList *mylist = (struct LList *)list;

	//这个是删除，如果没有找到就直接返回
	if (pos < 0 || pos > mylist->size)
	{
		return;
	}

	//找到这个位置
	struct LinkNode *myheader = &(mylist->header);
	//两个辅助指针，保存前面的，和后面的
	struct LinkNode *pCurrent = myheader->next;
	//一直循环直到找的pos节点
	for (int i = 0; i < pos; ++i)
	{
		myheader = pCurrent;
		pCurrent = pCurrent->next;
	}
	//直接让他的前驱节点的next链接它的后驱节点
	myheader->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	mylist->size--;

}
//按值删除
//传入链表信息结构
//传入一个节点
//一个回调函数，用户自己编写
void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	
	struct LList * mylist = (struct LList *)list;

	//两个辅助节点
	struct LinkNode *myliknode = &(mylist->header);
	struct LinkNode *pCurrrent = myliknode->next;
	//
	while (pCurrrent!= NULL)
	{	//pCurrent->data指向一个结构体
		if (compare(pCurrrent->data,data))
		{
			//删除节点，并释放
			myliknode->next=pCurrrent->next;
			free(pCurrrent);
			pCurrrent = NULL;
			mylist->size--;
			break;
		}
		myliknode = pCurrrent;
		pCurrrent = pCurrrent->next;		
	}
}

void Clear_LinkList(LinkList list)//清空链表
{

	if (NULL == list)
	{
		return;
	}
	//
	struct LList *mylist = (struct LList *)list;
	struct LinkNode *myheadder = mylist->header.next;
	struct LinkNode *mynext =NULL;
	while (myheadder->next != NULL)
	{
		mynext = myheadder->next;
		free(myheadder);
		myheadder = mynext;
		
	}
	mylist->header.next = NULL;
}

int Size_LinkList(LinkList list)//链表节点个数
{
	if (NULL == list)
	{
		return -1;
	}
	struct LList *mylist = (struct LList *)list;
	return mylist->size;
}

void Destroy_LinkList(LinkList list)//销毁链表
{
	if (NULL == list)
	{
		return;
	}
	Size_LinkList(list);	
	free(list);
	list = NULL;
}