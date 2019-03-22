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

// 在指定值后面插入数据data,如果值val不存在，则在尾部插入。
void insert_linklist(link_node * head, int val, int data)
{
	if (head == NULL)
		return;

	// 两个辅助指针
	link_node *p_prev = head;
	link_node *p_current = p_prev->next;

	while(p_current != NULL)
	{
		if (p_current->data == val)
			break;

		p_prev = p_current;
		p_current = p_prev->next;
	}

	// 创建新的节点
	link_node *newnode = (link_node*)malloc(sizeof(link_node));
	if (newnode == NULL)
		return;

	newnode->data = data;
	newnode->next = NULL;
	
	// 如果p_current为NULL，说明不存在值为val的节点
#if 0
	if (p_current == NULL)
	{
		printf("insert: 不存在值为%d的节点!\n", val);
		return;
	}
#endif
	// 新节点入链表
	//newnode->next = p_current;
	//p_prev->next = newnode;

	if (p_current == NULL)
	{
		printf("insert: 不存在值为%d的节点!\n", val);
		p_current->next = newnode;
	} else {
		newnode->next = p_current->next;
		p_current->next = newnode;
	}
}

void remove_linklist(link_node *head, int val)
{
	if (head == NULL)
		return;


	// 两个辅助指针
	link_node *p_prev = head;
	link_node *p_current = p_prev->next;

	while(p_current != NULL)
	{
		if (p_current->data == val)
			break;

		p_prev = p_current;
		p_current = p_prev->next;
	}

	// 如果p_current为NULL，表示没有找到
	if (p_current == NULL)
	{
		printf("remove: 不存在值为%d的节点!\n", val);
		return;
	}

	// 删除当前节点： 重新建立待删除节点(p_current)的前驱后继节点关系
	p_prev->next = p_current->next;
	// 释放待删除节点的内存
	free(p_current);
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

void Clear_linklist(link_node *head)
{
	if (NULL == head)
		return;

	// 辅助指针变量
	link_node *p_current = head->next;
	
	while(p_current != NULL)
	{
		// 先保存当前节点的下一个节点地址
		link_node *pNext = p_current->next;

		// 释放当前节点内存
		free(p_current);

		// p_current 指向下一个节点
		p_current = pNext;
	}
	head->next = NULL;
}

void operation_linklist(link_node *head)
{
	if (head == NULL)
		return;

	int val = -1;
	int data = -1;
	printf("please input add val:\n");
	scanf("%d", &val);
	if (val == -1)
		return;

	printf("please input add data:\n");
	scanf("%d", &data);

	//保存当前节点
	//link_node *p_current = head;

	insert_linklist(head, val, data);

	foreach_linklist(head);

	printf("please input remove val:\n");
	scanf("%d", &val);
	if (val == -1)
		return;

	remove_linklist(head, val);

	foreach_linklist(head);
}

int main()
{
	link_node *node = init_linklist();
	foreach_linklist(node);
	operation_linklist(node);
	destroy_linklist(node);

	return 0;
}
