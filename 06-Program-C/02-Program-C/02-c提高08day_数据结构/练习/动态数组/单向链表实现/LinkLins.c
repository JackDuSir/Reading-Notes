#include "LinkLins.h"







Linknode initlinklins()//初始化节点
{
	struct message *mymessage = malloc(sizeof(MS));
	if (mymessage == NULL)
	{
		return NULL;
	}
	mymessage->headder.data = NULL;
	mymessage->headder.next = NULL;
	mymessage->age = 0;

	return mymessage;
}


void insertnode(Linknode phead, int pos, void *data)//插入数据
{
	if (NULL == phead)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	MS *myphead = (MS *)phead;

	if ( pos < 0 || pos > myphead->age)
	{
		pos = myphead->age;
	}

	MN *pnod = &(myphead->headder);
	
	
	for (int i = 0; i < pos; ++i)
	{
		pnod = pnod->next;
	}

	MN * newnod = malloc(sizeof(MN));
	newnod->data = data;
	newnod->next = NULL;

	newnod->next = pnod->next;
	pnod->next = newnod;

	myphead->age++;

}

void stamp(Linknode phead, FOREACH show)//打印链表
{
	if (NULL == phead)
	{
		return;
	}

	MS *myphead = (MS*)phead;
	//打印从第二个节点开始
	MN *mydata = myphead->headder.next;

	while (mydata != NULL)
	{
		show(mydata->data);
		mydata = mydata->next;
	}
}

int nodenumber(Linknode phead)//返回一节点个数
{
	if (NULL == phead)
	{
		return -1;
	}

	MS *myphead = (MS *)phead;
	return myphead->age;

}
void deletenode(Linknode phead, int pos)//根据位置删除
{
	if (NULL == phead)
	{
		return;
	}
	MS *myphead = (MS *)phead;
	
	if (pos<0 || pos>myphead->age)
	{
		return;
	}
	MN *p1 = myphead->headder.next;
	MN *p2 = NULL;
	for (int i = 0; i < pos; ++i)
	{
		p2 = p1;
		p1 = p1->next;
	}

	p2->next = p1->next;
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
}