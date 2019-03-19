#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif

	struct mynod
	{
		void* data;
		struct mynod *next;
	};

	struct message
	{
		struct mynod headder;
		int age;
	};
	typedef void * Linknode;
	typedef struct message MS;
	typedef struct mynod MN;
	typedef void(*FOREACH)(void *);

	void* initlinklins();//初始化节点
	void insertnode(Linknode phead, int pos, void *data);//插入数据
	void stamp(Linknode phead, void(*show)(void *));//打印链表
	int nodenumber(Linknode phead);//返回一节点个数
	void deletenode(Linknode phean, int pos);//根据位置删除



	







#ifdef __cplusplus
}
#endif