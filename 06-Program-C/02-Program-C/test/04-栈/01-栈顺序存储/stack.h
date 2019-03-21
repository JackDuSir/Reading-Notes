/*************************************************************************
	> File Name: stack.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月21日 星期四 12时23分43秒
 ************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define MAX 1024

// 顺序栈数据结构
typedef struct _SeqStack
{
	void *data[MAX];	// 存放数据的数组
	int size;	// 栈中元素的个数
} SeqStack;

typedef void * Stack;

// 数据高下标的位置当做栈顶。因为不需要移动数组的元素在插入和删除中

// 初始化
Stack Init_SeqStack();

// 入栈
void Push_SeqStack(Stack stack, void *data);

// 出栈
void Pop_SeqStack(Stack stack);

// 获得栈顶元素
void *Top_SeqStack(Stack stack);

// 获得栈的大小
int Size_SeqStack(Stack stack);

// 销毁栈
void Destroy_SeqStack(Stack stack);


#ifdef __cplusplus
}
#endif
