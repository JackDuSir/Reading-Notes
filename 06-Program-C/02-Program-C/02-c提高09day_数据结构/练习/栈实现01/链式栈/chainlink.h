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

	void * init();//��ʼ��ջ
	void push(void *phead, void *data);//��ջ
	void pop(void *phead);//��ջ
	void * top(void *phead);//���ջ��
	int node(void *phead);//��ýڵ���
	void dest(void *phead);//����ջ



#ifdef __plusplus
}
#endif