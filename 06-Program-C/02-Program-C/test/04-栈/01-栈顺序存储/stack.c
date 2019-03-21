/*************************************************************************
	> File Name: stack.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 四  3/21 20:56:31 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

// 初始化
Stack Init_SeqStack()
{
	SeqStack *stack = malloc(sizeof(SeqStack));
	if (NULL == stack)
		return NULL;

	//memset(stack, 0, sizeof(SeqStack));
	stack->size = 0;
	int i = 0;
	for (i; i < MAX; ++i)
		stack->data[i] = NULL;
	return stack;
}

// 入栈
void Push_SeqStack(Stack stack, void *data)
{
	if (NULL == stack || NULL == data)
		return;

	SeqStack *seqStack = (SeqStack* )stack;
	if (seqStack->size == MAX)
		return;
	seqStack->data[seqStack->size++] = data;
}

// 出栈
void Pop_SeqStack(Stack stack)
{
	if (NULL == stack)
		return;

	SeqStack *seqStack = (SeqStack *)stack;
	if (seqStack->size == 0)
		return;

	seqStack->data[seqStack->size - 1] = NULL;
	seqStack->size--;
}

// 获得栈顶元素
void *Top_SeqStack(Stack stack)
{
	if (NULL == stack)
		return NULL;

	SeqStack *seqStack = (SeqStack *)stack;
	if (seqStack->size == 0)
			return NULL;

	return seqStack->data[seqStack->size - 1];
}

// 获得栈的大小
int Size_SeqStack(Stack stack)
{
	if (NULL == stack)
		return -1;

	SeqStack *seqStack = (SeqStack *)stack;
	return seqStack->size;
}

// 销毁栈
void Destroy_SeqStack(Stack stack)
{
	if (NULL == stack)
		return;

	free(stack);
	stack = NULL;
}

