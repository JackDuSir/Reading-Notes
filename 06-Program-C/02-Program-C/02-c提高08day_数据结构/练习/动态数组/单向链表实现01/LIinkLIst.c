#include "LinkList.h"

Linknode initnod()//初始化数据
{
	mynode * newnode = malloc(sizeof(mynode));
	if (NULL == newnode)
	{
		return;
	}

	newnode->mylinknod.arr = NULL;
	newnode->mylinknod.arr = NULL; 
	newnode->size = NULL;
}
void insert(Linknode headder, int pos, Linknode data)//插入数据
{
	if (NULL == headder)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	mynode *newheadder = (mynode *)headder;
	if (pos < 0 || pos>newheadder->size)
	{
		pos = newheadder->size;
	}
	mylink * newlink = &(newheadder->mylinknod);
	mylink * newLink = malloc(sizeof(mylink));
	newLink->arr = data;
	newLink->next = NULL;

	for (int i = 0; i < pos; ++i)
	{
		newlink = newlink->next;
	}

	newLink->next = newLink->next;
	newlink->next = newLink;
	newheadder->size++;

}
void print(Linknode phead, void(comprin)(void *))//打印数据
{

	if (NULL == phead)
	{
		return;
	}
	mynode *
	

}