#include"LinkQueue.h"


struct Person
{
	struct queuenode *qhean;
	char name[64];
	int age;
};


void * init_queuelink()//��ʼ������
{
	struct queuelink * myqueue = malloc(sizeof(struct queuelink));
	myqueue->head.next = NULL;
	myqueue->size = 0;
	//bcak�б������һ����ַ
	myqueue->back = &(myqueue->head);
	return myqueue;
}
void push_queuelink(void *Qlink, void *data)//��������
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
	//�ڶ�β���룬
	myqueue->back->next = mydata;
	//����Ҫ�Ѳ���ýڵ�ǰ����ֽ���Ϊ��
	mydata->next = NULL;
	//����������õ�ַ
	myqueue->back = mydata;

	myqueue->size++;
}
void pop_queuelink(void *Qlink)//����
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
void *top_queuelink(void *Qlink)//���ջ��
{
	if (NULL == Qlink)
	{
		return NULL;
	}

	struct queuelink * myqueue = (struct queuelink *)Qlink;
	return myqueue->head.next;
}


int Size_queuelink(void*Qlink)//��ö��нڵ��С
{
	if (Qlink == NULL)
	{
		return 0;
	}

	struct queuelink * myqueue = (struct queuelink *)Qlink;
	return myqueue->size;
}