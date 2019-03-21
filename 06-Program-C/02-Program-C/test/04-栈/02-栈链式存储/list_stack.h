/*************************************************************************
	> File Name: list_stack.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月21日 星期四 15时49分09秒
 ************************************************************************/

#pragma once

typedef struct _StackNode
{
	struct _StackNode *next;
} StackNode;

typedef struct _LStack
{
	StackNode header;	// 头结点
	int size;
} LStack;

typedef void * ListStack;

#ifdef __cplusplus
extern "C" {
#endif

// 初始化
ListStack Init_ListStack();

// 入栈
void Push_ListStack(ListStack stack, void *data);

// 出栈
void Pop_ListStack(ListStack stack);

// 获得栈顶元素
void *Top_ListStack(ListStack stack);

// 获得栈大小
int Size_ListStack(ListStack stack);

// 销毁栈
void Destroy_ListStack(ListStack stack);

#ifdef __cplusplus
}
#endif
