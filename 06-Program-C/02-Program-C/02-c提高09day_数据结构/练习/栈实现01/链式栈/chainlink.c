#include"chainlink.h"


void * init()//��ʼ��ջ
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
void push(void *phead, void *data)//��ջ
{
	if (NULL == phead)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	//ÿһ�ζ�����ջ������
	struct trust *pp = (struct trust *)phead;
	//���û��������������ת��Ϊ
	//�ô���һ���ṹ��ָ�룬ǰ�ĸ��ֽ�Ϊ�����ǰ���ת��Ϊstruct pheadnode*�������ǿ���
	//����struct pheadnode���͵��ֽ�(�������ĸ��ֽ�)
	struct pheadnode* ps = (struct pheadnode*)data;
	//�ò�����ȱ��浱ǰ�ڵ����һ���ڵ�
	ps->pnext = pp->next.pnext;
	pp->next.pnext = ps;
	//�ڵ�Ӽ�
	pp->size++;


}
void pop(void *phead)//��ջ����վջ����ջ
{
	if (NULL == phead)
	{
		return;
	}
	struct trust *pp = (struct trust *)phead;
	//�ȱ���ͷ��㣬Ȼ����ͷ������һ���ڵ��Ϊͷ���
	struct pheadnode *p1 = pp->next.pnext;
	pp->next.pnext = p1->pnext;
	pp->size--;
	
}
void * top(void *phead)//���ջ��
{
	if (NULL == phead)
	{
		return	NULL;
	}

	struct trust *pp = (struct trust *)phead;
	return pp->next.pnext;

}
int node(void *phead)//��ýڵ���
{
	if (NULL == phead)
	{
		return -1;
	}
	struct trust *pp = (struct trust *)phead;
	return pp->size;


}
void dest(void *phead)//����ջ
{
	if (NULL == phead)
	{
		return;
	}

	free(phead);
	phead = NULL;
}