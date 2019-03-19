#include<stdio.h>
#include<string.h>
#include<stdlib.h>



struct node
{
	void *data;
	struct node *head;
	struct node *back;
};


struct linklist
{
	struct node headnod;
	int size;
};


void *init();//初始化
void inser(void *linklist, int pos, void *data);//插入
void  show(void *linklist, void(*print)(void *));//正向打印
void deletenode(void *linklist, int pos);//按照位置删除
void reverseshow(void *linklist, void(*print)(void *));//反向打印
void destroy(void *linklist);//销毁