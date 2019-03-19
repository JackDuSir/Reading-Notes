#include "stack.h"

//��ʼ��
SeqStack Init_SeqStack()
{
	struct SStack *pp = malloc(sizeof(struct SStack));
	if (NULL == pp)
	{
		return NULL;
	}
	//ֱ�Ӱ�����ڴ��ʼ��Ϊ��
	memset(pp, 0, sizeof(struct SStack));
	pp->size = 0;
	return pp;
}
//��ջ
void Push_SeqStack(SeqStack stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}
	//����ת��
	struct SStack *pp = (struct SStack *)stack;
	if (pp->size == MAX)
	{
		return;
	}
	//��ջ�����룬���±�λ��
	//�ڵ�ǰ����±�λ�ò��룬����ջ��
	pp->data[pp->size] = data;
	pp->size++;

}
//��ջ
void Pop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct SStack *pp = (struct SStack *)stack;
	//�������±����
	pp->size--;
}
//���ջ��Ԫ��
SeqStack Top_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{ 
		return NULL;
	}

	struct SStack *pp = (struct SStack *)stack;
	 return pp->data[pp->size - 1];

}
//���ջ�Ĵ�С
int Size_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{
		return -1;
	
	}

	struct SStack *pp = (struct SStack *)stack;
	return pp->size;

}
//����ջ
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{
		return;
	}

	free(stack);

}