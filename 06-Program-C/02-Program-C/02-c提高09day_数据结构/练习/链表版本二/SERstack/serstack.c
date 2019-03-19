#include"serstack.h"

SeqStack Init_SeqStack()
{
	struct SStack *pp = malloc(sizeof(struct SStack));
	memset(pp, 0, sizeof(struct SStack));
	pp->size = 0;
	return pp;

}
//��ջ
void Push_SeqStack(SeqStack stack, SeqStack data)
{
	if ( NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	
	struct SStack *pp = (struct SStack *)stack;
	if (pp->size == MAX)
	{
		return;
	}

	pp->data[pp->size] = data;
	pp->size++;

}
//��ջ
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}
	struct SStack *pp = (struct SStack *)stack;
	if (pp->size == 0)
	{
		return;
	}
	pp->data[pp->size-1] = NULL;
	pp->size--;

}
//���ջ��Ԫ��
SeqStack Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	struct SStack *pp = (struct SStack *)stack;

	if (pp->size == 0)
	{
		return NULL;
	}
	
	return pp->data[pp->size - 1];
}
//���ջ�Ĵ�С
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct SStack *pp = (struct SStack *)stack;

	return pp->size;

}
//����ջ
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}
	
	free(stack);

}