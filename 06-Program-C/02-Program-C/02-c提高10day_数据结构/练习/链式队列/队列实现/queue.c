#include "queue.h"

//��ʼ��
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
//���
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
//����
void Pop_LinkQueue(LinkQueue queue);
//��ö�ͷԪ��
void* Front_LinkQueue(LinkQueue queue);
//��ö�βԪ��
void* Back_LinkQueue(LinkQueue queue);
//��С
int Size_LinkQueue(LinkQueue queue);
//���ٶ���
void Destroy_LinkQueue(LinkQueue queue);