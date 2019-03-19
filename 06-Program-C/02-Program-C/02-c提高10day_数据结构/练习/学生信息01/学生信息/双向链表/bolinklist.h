#pragma once 
#include <stdio.h>
#include<stdlib.h>
#include<string.h>



//节点
struct LinklistNode
{
	void *data;
	struct LinklistNode *haed;
	struct LinklistNode* next;
};
//链表信息
struct LinklistMessage
{
	struct LinklistNode linkhead;
	int size;
};

typedef struct LinklistNode Node;
typedef struct LinklistMessage Link;

//初始化链表
void *InitLink();

//插入数据 按照位置
void InsertNode(void *linkhead, int pos, void *data);
//删除数据 按照位置
void DeleteNode(void *linkhead, int pos);
//遍历数据
void show(void *linkhead,void(*print)(void *));
//反向遍历
void revshow(void *linkhead, void(*print)(void *));
//销毁链表
void deslinklist(void *linkhead);
//打印节点个数
void NodeAmount(void *linkhead);
//按值查找
void PriceSeek(void *linkhead, void* data);