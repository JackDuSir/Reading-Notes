#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif
	struct linknod
	{
		char *arr;
		struct linknod *next;
	};

	struct nodedata
	{
		struct linknod mylinknod;
		int size;
	};
	typedef struct linknod mylink;
	typedef struct nodedata mynode;
	typedef void * Linknode;


	
	void* initnod();//初始化数据
	void insert(Linknode headder, int pos, Linknode data);//插入数据
	void print(Linknode phead);//打印数据









#ifdef __cplusplus
}
#endif