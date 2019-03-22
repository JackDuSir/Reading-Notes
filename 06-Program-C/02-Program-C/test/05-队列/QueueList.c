/*************************************************************************
	> File Name: QueueList.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月22日 星期五 15时01分12秒
 ************************************************************************/

#include"QueueList.h"

// 初始化
QueueList Init_LinkQueue()
{
	LinkQueue *queue = malloc(sizeof(LinkQueue));
	if (NULL == queue)
		return NULL;

	queue->header.next = NULL;
	queue->size = 0;
	queue->tail = &(queue->header);

	return queue;
}

// 入队
void Push_LinkQueue(QueueList queue, void *data)
{
	if (NULL == queue ||NULL == data)
		return;

	LinkQueue *link_queue = (LinkQueue *)queue;
	QueueNode *queue_node = (QueueNode *)data;

	link_queue->tail->next = queue_node;
	queue_node->next = NULL;

	// 更新尾指针
	link_queue->tail = queue_node;
	link_queue->size++;
}

// 出队
void Pop_LinkQueue(QueueList queue)
{
	if (NULL == queue)
		return;

	LinkQueue *link_queue = (LinkQueue *)queue;
	if (link_queue->size == 0)
		return;
	
	if (link_queue->size == 1)
	{
		link_queue->header.next = NULL;
		link_queue->tail = &(link_queue->header);
		link_queue->size--;

		return;
	}

	QueueNode *pDel = link_queue->header.next;
	link_queue->header.next = pDel->next;
	link_queue->size--;
}

// 获得队头元素
void *Head_LinkQueue(QueueList queue)
{
	if (NULL == queue)
		return NULL;

	LinkQueue *link_queue = (LinkQueue *)queue;

	return link_queue->header.next;
}

// 获得队尾元素
void *Tail_LinkQueue(QueueList queue)
{
	if (NULL == queue)
		return NULL;

	LinkQueue *link_queue = (LinkQueue *)queue;

	return link_queue->tail;
}

// 大小
int Size_LinkQueue(QueueList queue)
{
	if (NULL == queue)
		return -1;

	LinkQueue *link_queue = (LinkQueue *)queue;

	return link_queue->size;
}

// 销毁队列
void Destroy_LinkQueue(QueueList queue)
{
	if (NULL == queue)
		return;

	free(queue);
	queue = NULL;
}


