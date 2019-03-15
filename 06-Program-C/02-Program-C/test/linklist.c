/*************************************************************************
	> File Name: init_linklist.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月15日 星期五 19时51分05秒
 ************************************************************************/
/*
 * 建立带有头结点的单向链表，循环创建结点，结点数据域中的数值从键盘输入，以 -1 作为输入结束标志，链表的头结点地址由函数值返回.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct _LINKNODE 
{
	int data;
	struct _LINKNODE *next;
}link_node;

link_node *init_linklist()
{
	link_node *head = NULL;
	head = (link_node*)malloc(sizeof(link_node));
	if (head == NULL)
		return NULL;
	head->data = -1;
	head->next = NULL;

	//保存当前节点
	link_node *p_current = head;
	int data = -1;

	while(1)
	{
		printf("please input data:\n");
		scanf("%d", &data);
		if (data == -1)
			break;

		link_node *newnode = (link_node*)malloc(sizeof(link_node));
		if (newnode == NULL)
			break;

		newnode->data = data;
		newnode->next = NULL;

		//新节点入链表，也就是将节点插入到最后一个节点的下一个位置
		p_current->next = newnode;
		//更新辅助指针 p_current
		p_current = newnode;
	}
	return head;
}

void foreach_linklist(link_node *head)
{
	if (head == NULL)
		return;

	link_node *p_current = head->next;
	while(p_current != NULL)
	{
		printf("linknode data = (%d)\n", p_current->data);
		p_current = p_current->next;
	}
}

void destroy_linklist(link_node *head)
{
	if (head == NULL)
		return;

	link_node *p_current = head;
	while(p_current != NULL)
	{
		//缓存当前节点的下一个节点
		link_node *p_next = p_current->next;
		free(p_current);
		p_current = p_next;
	}
}

int main()
{
	link_node *node = init_linklist();
	foreach_linklist(node);
	destroy_linklist(node);

	return 0;
}
