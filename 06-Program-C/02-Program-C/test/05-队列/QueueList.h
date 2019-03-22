/*************************************************************************
	> File Name: QueueList.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月22日 星期五 14时15分45秒
 ************************************************************************/

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _QueueNode
{
	struct _QueueNode *next;
} QueueNode;

typedef struct _LinkQueue
{
	QueueNode header;	// 头结点
	int size;
	QueueNode *tail;	// 尾指针，始终指向链表的最后一个节点
} LinkQueue;

typedef void *QueueList;

#ifdef __cplusplus
extern "C" {
#endif

// 初始化
QueueList Init_LinkQueue();

// 入队
void Push_LinkQueue(QueueList queue, void *data);

// 出队
void Pop_LinkQueue(QueueList queue);

// 获得队头元素
void *Head_LinkQueue(QueueList queue);

// 获得队尾元素
void *Tail_LinkQueue(QueueList queue);

// 大小
int Size_LinkQueue(QueueList queue);

// 销毁队列
void Destroy_LinkQueue(QueueList queue);

#ifdef __cplusplus
}
#endif

