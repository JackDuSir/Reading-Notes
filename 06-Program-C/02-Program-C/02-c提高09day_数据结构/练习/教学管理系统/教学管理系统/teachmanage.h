#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifdef __cplusplus
extern "C"{
#endif 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

	
	struct site
	{
		struct site *next;
	};

	struct teacher
	{
		struct site head;
		unsigned int size;
	};

	void  init_data(void ** teacher);//初始化数据
	void insert_data(void *linklins, unsigned int pos, void *data);//插入数据
	void delete_data(void *linklins, unsigned int pos);//根据位置删除数据
	void find_data(void *linklins, unsigned int pos, void(*print)(void *));//查找
	void findall_data(void *linklins, void(*print)(void *));//遍历
	void alter_data(void *linklins, unsigned int pos, void *data);//修改
	void pricefine_data(void *linklins, void *data, int(*compare)(void *, void*), void(*prin)(void *));//按照值查找



#ifdef __cplusplus
}
#endif 