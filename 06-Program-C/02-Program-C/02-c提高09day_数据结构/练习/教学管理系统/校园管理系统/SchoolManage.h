#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodeMessage
{
	void *data;
	struct nodeMessage *next;
};

struct linkMessage
{
	struct nodeMessage head;
	int size;
};

typedef struct nodeMessage * nodemessage;
typedef struct linkMessage * linkmessage;

void*init();//初始化
void insertnode(void *link, int pos, void *data);//插入数据
void deletenode(void *link, int pos);//删除节点
void seeknode(void *link, int pos, void(*print)(void *));//查找节点
void alternode(void *link, int pos);//修改节点
void shownode(void *link, void(*print)(void *));//打印节点