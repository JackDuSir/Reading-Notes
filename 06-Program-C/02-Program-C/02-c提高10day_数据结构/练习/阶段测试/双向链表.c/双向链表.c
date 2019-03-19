#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点信息
typedef struct node
{
	int data;
	struct _node *pre;
	struct _node *next;
}Node;



void * init()
{
	Node *mynode = malloc(sizeof(Node));
	if (NULL == mynode)
	{
		return NULL;
	}
	mynode->next = NULL;
	mynode->pre = NULL;
	
}

//插入数据
void insert(void *linknode, int data)
{
	if (NULL == linknode)
	{
		return;
	}

	Node *mylink = (Node *)linknode;
	mylink->data = data;
	if (mylink->pre == NULL )
	{
		mylink->data = data;
		mylink->pre = &(data);
	}

	mylink->pre = mylink->next;
	mylink->next = &(data);	
}





int main()
{
	system("pause");

}