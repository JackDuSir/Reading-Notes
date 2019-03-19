#include"seqlinklist.h"


void *init_link()//��ʼ������������Ϣ�ڵ�
{
	struct linklistmessage *mylinklist = malloc(sizeof(struct linklistmessage));
	if (mylinklist == NULL)
	{
		return NULL;
	}
	mylinklist->head.next = NULL;
	mylinklist->head.str = NULL;
	mylinklist->size = 0;
	return mylinklist;
}

void insert_link(void *mylink, unsigned int pos, void *data)//����ڵ�
{
	if (NULL == mylink)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct linklistmessage *link = (struct linklistmessage *)mylink;
	if (pos<0 || pos>link->size)
	{
		pos = link->size;
	}

	struct nodemessage *pcurr = &(link->head);
	for (unsigned int  i = 0; i < pos; ++i)
	{
		pcurr = pcurr->next;
	}
	//�����µĽڵ�
	struct nodemessage * newnode = malloc(sizeof(struct nodemessage));

	newnode->str = data;

	newnode->next = NULL;

	newnode->next = pcurr->next;

	pcurr->next = newnode;



	link->size++;
}

void delete_link(void *mylink, unsigned int pos)//ɾ���ڵ�
{
	if (NULL == mylink)
	{
		return;
	}
	struct linklistmessage *link = (struct linklistmessage *)mylink;

	if (pos<0 || pos>link->size)
	{
		return;
	}
	struct nodemessage *pcurr = &(link->head);

	struct nodemessage *pru = NULL;
	for (unsigned int i = 0; i < pos; ++i)
	{
		pcurr = pcurr->next;
	}
	pru = pcurr->next;
	pcurr->next = pru->next;
	free(pru);
	pru= NULL;
	link->size--;
}

void fineall_link(void *mylink, void(*print)(void *))//��������
{
	if (NULL == mylink)
	{
		return;
	}
	if (NULL == print)
	{
		return;
	}

	struct linklistmessage *link = (struct linklistmessage*)mylink;
	struct nodemessage *node = link->head.next;

	for ( unsigned int i = 0; i < link->size; ++i)
	{
		print(node->str);
		node = node->next;
	}
}

unsigned int link_node(void *mylink)//�ڵ����
{
	if (NULL == mylink)
	{
		return -1;
	}
	struct linklistmessage *link = (struct linklistmessage *)mylink;
	return link->size;

}

void findnode_link(void *mylink, unsigned int pos, void (*print)(void *d1))
{
	if (NULL == mylink)
	{
		return;
	}
	struct linklistmessage *linklist = (struct linklistmessage *)mylink;
	if (pos < 0 || pos > linklist->size)
	{
		return;
	}
	struct nodemessage *pcuure = &(linklist->head);
	for (unsigned int i = 0; i < pos; ++i)
	{
		pcuure = pcuure->next;
	}

	print(pcuure->str);
}