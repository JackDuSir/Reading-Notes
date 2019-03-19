#include"LinkQueue.h"


struct Person
{
	struct queuenode *qhean;
	char name[64];
	int age;
};


void * init_queuelink()//初始化队列
{
	struct queuelink * myqueue = malloc(sizeof(struct queuelink));
	myqueue->head.next = NULL;
	myqueue->size = 0;
	//bcak中保存的是一个地址
	myqueue->back = &(myqueue->head);
	return myqueue;
}
void push_queuelink(void *Qlink, void *data)//插入数据
{
	if (NULL == Qlink)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct queuelink * myqueue = (struct queuelink *)Qlink;
	struct queuenode *mydata = (struct queuenode *)data;
	//在队尾插入，
	myqueue->back->next = mydata;
	//我们要把插入得节点前面的字节置为空
	mydata->next = NULL;
	//保存最后插入得地址
	myqueue->back = mydata;

	myqueue->size++;
}
void pop_queuelink(void *Qlink)//出队
{
	if (NULL == Qlink)
	{
		return;
	}
	struct queuelink * myqueue = (struct queuelink *)Qlink;
	if (myqueue->size == 0)
	{
		return;
	}
	if (myqueue->size == 1)
	{
		myqueue->head.next = NULL;
		myqueue->back = &(myqueue->head);
		myqueue->size--;
		return;
	}

	struct queuenode *pcur = myqueue->head.next;
	myqueue->head.next = pcur->next;
	myqueue->size--;

}
//
void *top_queuelink(void *Qlink)//获得栈顶
{
	if (NULL == Qlink)
	{
		return NULL;
	}

	struct queuelink * myqueue = (struct queuelink *)Qlink;
	return myqueue->head.next;
}


int Size_queuelink(void*Qlink)//获得队列节点大小
{
	if (Qlink == NULL)
	{
		return 0;
	}

	struct queuelink * myqueue = (struct queuelink *)Qlink;
	return myqueue->size;
}