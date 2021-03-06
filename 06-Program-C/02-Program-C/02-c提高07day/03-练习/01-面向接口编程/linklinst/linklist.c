#include "linklist.h"




node * init(node *phead)//初始化链表
{
	phead->data = 0;
	phead->next = NULL;
	return phead;
}
node* addback(node *phead, int key)//尾部插入
{
	node *newnode = malloc(sizeof(node));
	newnode->data = key;
	newnode->next = NULL;
	node *pphead = phead;
	if ( pphead == NULL)
	{
		phead = newnode;
		return phead;
	}
	while (pphead->next != NULL)
	{
		pphead = pphead->next;
	}
	pphead->next = newnode;

	return phead;
}
node * addhead(node *phead, int key)//头插
{
	node *newnode = malloc(sizeof(node));
	newnode->data = key;
	newnode->next = NULL;
	if (phead == NULL)
	{
		phead = newnode;
		return phead;
	}
	newnode->next = phead;
	phead = newnode;
	return phead;
}

node *alter(node *phead, int outdata, int newdata)//在outdat后插入数据
{
	node *newnode = malloc(sizeof(node));
	newnode->data = newdata;
	newnode->next=NULL;
	if (NULL == phead)
	{
		phead = newnode;
		return phead;
	}
	node *p1 = phead;
	while (p1->next != NULL)
	{
		if (p1->data == outdata)
		{
			break;
		}
		p1 = p1->next;
	}

	newnode->next = p1->next;
	p1->next = newnode;
	return phead;
}

void showlinklist(node *phead)//打印数据
{
	if (NULL == phead)
	{
		return;
	}
	node *p1 = phead;
	while (p1 != NULL)
	{
		printf("%d  %p  %p\n", p1->data, p1, p1->next);
		p1 = p1->next;
	}

}

node *delete(node *phead, int outdata)//删除某一个节点
{
	if (phead == NULL)
	{
		return phead;
	}
	node *p1 = phead;
	node *p2 = NULL;
	while (p1 != NULL)
	{
		if (p1->data == outdata)
		{
			break;
		}
		p2 = p1;
		p1 = p1->next;
	}
	if (p1 == phead)
	{
		phead = p1->next;
		free(p1);
		return phead;
	}
	p2->next = p1->next;
	free(p1);
	return phead;
}


node *rev(node *phead)
{
	if (NULL == phead || phead->next == NULL)
	{
		return phead;
	}
	node *p1 = phead;
	node *p2 = phead->next;
	node *p3 = NULL;
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;

		p1 = p2;
		p2 = p3;
	}
	phead->next = NULL;
	phead = p1;
	return phead;
}

//合并链表，开辟一个新链表
void mergelinklist(node *p1, node *p2)
{
	node *pp1 = p1;
	node *pp2 = p2;
	node *pp3 = NULL;
	while (pp1 != NULL || pp2 != NULL)
	{
		if (pp1 != NULL && pp2 != NULL)
		{
			if (pp1->data > pp2->data)
			{
				pp3 = addback(pp3, pp2->data);
				pp2 = pp2->next;
			}
			else
			{
				pp3 = addback(pp3, pp1->data);
				pp1 = pp1->next;
			}
		}
		else
		{
			while (pp1 != NULL)
			{
				pp3 = addback(pp3, pp1->data);
				pp1 = pp1->next;
			}
			while (pp2 != NULL)
			{
				pp3 = addback(pp3, pp2->data);
				pp2 = pp2->next;
			}
		}

	}
	showlinklist(pp3);
}

int guiallnode(node *phead)//递归统计节点
{
	if (phead == NULL)
	{
		return 0;
	}
	else
	{
		return 1+guiallnode(phead->next);
	}
}

node* location(node *phead, unsigned int k)//查找倒数第k个节点
{
	node *p1 = phead;
	node *p2 = phead;

	//首先判断是否为空，以及输入的是否是零
	if (phead == NULL || k == 0)
	{
		return NULL;
	}
	//先让一个节点先走k-1个，然后后面的节点开始走
	for (unsigned int i = 0; i < k - 1 ; ++i)
	{
		//判断是否有那么多节点
		if (p1->next != NULL)
		{
			p1 = p1->next;
		}
		else
		{
			return NULL;
		}
	}

	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	

	return p2;

}

node *middlenode(node *phead)
{
	node *p1 = NULL;
	node *p2 = NULL;
	if (phead == NULL || phead->next == NULL)
	{
		return phead;
	}
	p1 = phead;
	p2 = phead;

	while (p2->next != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
		if (p2->next != NULL)
		{
			p2 = p2->next;
		}

	}

	return p1;
}