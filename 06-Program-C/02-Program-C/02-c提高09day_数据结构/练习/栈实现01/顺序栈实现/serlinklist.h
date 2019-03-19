#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
//1.顺序栈的结构体，包含栈的信息
//2.栈的初始化，分配内存
//3.压栈
//4.出栈
//5.获得栈顶
	//获得栈的大小
//6.判断溢出
//7.销毁

	struct SStack
	{
		//void *可存放任何类型地址
		void *data[MAX];
		int size;//栈中元素的个数
	};

	void *init_seqstak();//初始化栈
	void push_seqstack(void *stack, void *data);//入栈
	void pop_seqstack(void *stack);//出栈
	void *top(void *stack);//获得栈顶
	int size_seqstack(void *stack);//获得栈的大小
	void Destory_seqstack(void* stack);//销毁栈

	
#ifdef __cplusplus
}
#endif