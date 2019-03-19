#include"SchoolManage.h"

void * init()//��ʼ��
{
	linkmessage  mylink = (linkmessage)malloc(sizeof(struct linkMessage));
	if (NULL == mylink)
	{
		return NULL;
	}


	mylink->head.next = NULL;
	mylink->head.data = NULL;
	mylink->size = 0;
	return mylink;
}



void insertnode(void *link, int pos, void *data)//��������
{
	if (NULL == link || data == NULL)
	{
		return;
	}
	linkmessage mylink = (linkmessage)link;
	if (pos<0 || pos>mylink->size)
	{
		pos = mylink->size;
	}
	nodemessage newnode = (nodemessage)malloc(sizeof(struct nodeMessage));
	newnode->data = data;
	newnode->next = NULL;
	nodemessage pCurrent = &(mylink->head);
	if (NULL == newnode)
	{
		return;
	}

	newnode->data = data;
	newnode->next = NULL;

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	mylink->size++;
}
void deletenode(void *link, int pos)//ɾ���ڵ�
{
	if (NULL == link)
	{
		return;
	}
	linkmessage mylink = (linkmessage)link;
	nodemessage pCurrent = &(mylink->head);
	nodemessage pre = NULL;
	if (pos<0 || pos > mylink->size)
	{
		return;
	}
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}
	pre = pCurrent->next;
	pCurrent->next = pre->next;

	free(pre);
	mylink->size--;

}
void seeknode(void *link,int pos,void(*print)(void *))//���ҽڵ�
{
	if (NULL == link)
	{
		return;
	}
	linkmessage mylink = (linkmessage)link;
	nodemessage pCurrent = &(mylink->head);

	if (pos<0 || pos>mylink->size)
	{
		printf("����������ݲ���ȷ��");
		return;
	}

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	print(pCurrent->next);

}
void alternode(void *link, int pos);//�޸Ľڵ�

void shownode(void *link, void(*print)(void *))
{
	if (NULL == link)
	{
		return;
	}
	linkmessage mylink = (linkmessage)link;
	nodemessage pCurrent = mylink->head.next;
	while (pCurrent!=NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}