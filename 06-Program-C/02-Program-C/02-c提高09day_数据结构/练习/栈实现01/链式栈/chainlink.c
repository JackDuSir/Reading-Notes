#include"chainlink.h"


void * init()//初始化栈
{
	struct trust *pp = malloc(sizeof(struct trust));
	if (NULL == pp)
	{
		return NULL;
	}
	pp->next.pnext = NULL;
	pp->size = 0;
	return pp;

}
void push(void *phead, void *data)//入栈
{
	if (NULL == phead)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	//每一次都是在栈顶插入
	struct trust *pp = (struct trust *)phead;
	//把用户传入的数据类型转换为
	//用传入一个结构体指针，前四个字节为空我们把它转换为struct pheadnode*这样我们可以
	//访问struct pheadnode类型的字节(这里是四个字节)
	struct pheadnode* ps = (struct pheadnode*)data;
	//让插入的先保存当前节点的下一个节点
	ps->pnext = pp->next.pnext;
	pp->next.pnext = ps;
	//节点加加
	pp->size++;


}
void pop(void *phead)//出栈，从站栈顶出栈
{
	if (NULL == phead)
	{
		return;
	}
	struct trust *pp = (struct trust *)phead;
	//先保存头结点，然后让头结点的下一个节点成为头结点
	struct pheadnode *p1 = pp->next.pnext;
	pp->next.pnext = p1->pnext;
	pp->size--;
	
}
void * top(void *phead)//获得栈顶
{
	if (NULL == phead)
	{
		return	NULL;
	}

	struct trust *pp = (struct trust *)phead;
	return pp->next.pnext;

}
int node(void *phead)//获得节点数
{
	if (NULL == phead)
	{
		return -1;
	}
	struct trust *pp = (struct trust *)phead;
	return pp->size;


}
void dest(void *phead)//销毁栈
{
	if (NULL == phead)
	{
		return;
	}

	free(phead);
	phead = NULL;
}