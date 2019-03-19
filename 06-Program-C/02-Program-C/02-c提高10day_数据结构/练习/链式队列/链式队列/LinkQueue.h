#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif



	//节点信息
	struct queuenode
	{
		struct queuenode *next;

	};


	//队列信息
	struct queuelink
	{
		struct queuenode head;
		int size;
		struct queuenode * back;
	};


	void * init_queuelink();//初始化队列
	void push_queuelink(void *Qlink, void *data);//插入数据
	void pop_queuelink(void *Qlink);//出队
	void *top_queuelink(void *Qlink);//弹出数
	int Size_queuelink(void*Qlink);//大小
	void Destroy_queuelink(void*Qlink);







#ifdef __cplusplus
}
#endif