#include"SchoolManage.h"

void * init()//初始化
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



void insertnode(void *link, int pos, void *data)//插入数据
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
void deletenode(void *link, int pos)//删除节点
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
void seeknode(void *link,int pos,void(*print)(void *))//查找节点
{
	if (NULL == link)
	{
		return;
	}
	linkmessage mylink = (linkmessage)link;
	nodemessage pCurrent = &(mylink->head);

	if (pos<0 || pos>mylink->size)
	{
		printf("你输入的内容不正确！");
		return;
	}

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	print(pCurrent->next);

}
void alternode(void *link, int pos);//修改节点

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