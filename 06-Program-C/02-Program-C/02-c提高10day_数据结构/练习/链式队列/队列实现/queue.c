#include "queue.h"

//初始化
LinkQueue Init_LinkQueue()
{
	struct LQueue *myqueue = malloc(sizeof(struct LQueue));
	if (NULL == myqueue)
	{
		return NULL;
	}
	myqueue->header.next = NULL;
	myqueue->rear = &(myqueue->header);
	myqueue->size--;

	return myqueue;

}
//入队
void Push_LinkQueue(LinkQueue queue, void *data)
{
	if (NULL == queue)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LQueue *myqueue = (struct LQueue *)queue;
	myqueue->rear->next = (struct QueueNode *)data;
	myqueue->rear = &()



}
//出队
void Pop_LinkQueue(LinkQueue queue);
//获得队头元素
void* Front_LinkQueue(LinkQueue queue);
//获得队尾元素
void* Back_LinkQueue(LinkQueue queue);
//大小
int Size_LinkQueue(LinkQueue queue);
//销毁队列
void Destroy_LinkQueue(LinkQueue queue);