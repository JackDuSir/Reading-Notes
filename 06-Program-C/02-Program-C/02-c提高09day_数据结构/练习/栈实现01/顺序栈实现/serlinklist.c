#include "serlinklist.h"

void *init_seqstak()//初始化栈
{
	struct SStack *mylink = malloc(sizeof(struct SStack));
	if (NULL == mylink)
	{
		return NULL;
	}
	memset(mylink, 0, sizeof(struct SStack));
	mylink->size = 0;
	return mylink;
}
void push_seqstack(void *stack, void *data)//入栈
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return ;
	}
	struct SStack *mylink = (struct SStack *)stack;
	if (mylink->size == MAX)
	{
		return ;
	}
	
	mylink->data[mylink->size] = data;
	mylink->size++;



}
void pop_seqstack(void *stack)//出栈
{
	if (NULL == stack)
	{
		return;
	}
	struct SStack *mylink = (struct SStack *)stack;
	if (mylink->size == 0)
	{
		return;
	}
	mylink->size--;
	
}
void *top(void *stack)//获得栈顶
{
	if (NULL == stack)
	{
		return NULL;
	}
	
	struct SStack *mylink = (struct SStack *)stack;
	if (mylink->size == 0)
	{
		return NULL;
	}
	//
	return mylink->data[mylink->size - 1];


}
int size_seqstack(void *stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct SStack *mylink = (struct SStack *)stack;
	return mylink->size;


}


void Destory_seqstack(void* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}