#include"serstack.h"

SeqStack Init_SeqStack()
{
	struct SStack *pp = malloc(sizeof(struct SStack));
	memset(pp, 0, sizeof(struct SStack));
	pp->size = 0;
	return pp;

}
//入栈
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
//出栈
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
//获得栈顶元素
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
//获得栈的大小
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct SStack *pp = (struct SStack *)stack;

	return pp->size;

}
//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}
	
	free(stack);

}