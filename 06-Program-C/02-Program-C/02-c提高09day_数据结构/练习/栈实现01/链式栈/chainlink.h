#pragma once
#ifdef __plusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	struct pheadnode
	{
		struct pheadnode *pnext;
	};
	
	struct trust
	{
		struct pheadnode next;
		int size;
	};

	void * init();//初始化栈
	void push(void *phead, void *data);//入栈
	void pop(void *phead);//出栈
	void * top(void *phead);//获得栈顶
	int node(void *phead);//获得节点数
	void dest(void *phead);//销毁栈



#ifdef __plusplus
}
#endif