/*************************************************************************
	> File Name: list_stack.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 四  3/21 23:26:52 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list_stack.h"

// 初始化
ListStack Init_ListStack()
{
	LStack *stack_header = malloc(sizeof(LStack));
	if (NULL == stack_header)
		return NULL;

	stack_header->header.next = NULL;
	stack_header->size = 0;

	return stack_header;
}

// 入栈
void Push_ListStack(ListStack stack, void *data)
{
	if (NULL == stack || NULL == data)
		return;

	LStack *list_stack = (LStack *)stack;
	StackNode *stack_node = (StackNode *)data;

	stack_node->next = list_stack->header.next;
	list_stack->header.next = stack_node;
	++(list_stack->size);
}

// 出栈
void Pop_ListStack(ListStack stack)
{
	if (NULL == stack)
		return;

	LStack *list_stack = (LStack *)stack;
	if (list_stack->size == 0)
		return;

	// 缓存第一个节点
	StackNode *pFirst = list_stack->header.next; // ?

	list_stack->header.next = pFirst->next;	
	list_stack->size--;
}

// 获得栈顶元素
void *Top_ListStack(ListStack stack)
{
	if (NULL == stack)
		return NULL;

	LStack *list_stack = (LStack *)stack;
	if (list_stack->size == 0)
		return NULL;

	return list_stack->header.next;
}

// 获得栈大小
int Size_ListStack(ListStack stack)
{
	if (NULL == stack)
		return -1;

	LStack *list_stack = (LStack *)stack;
	return list_stack->size;
}

// 销毁栈
void Destroy_ListStack(ListStack stack)
{
	if (NULL == stack)
		return;

	free(stack);
	stack = NULL;
}

