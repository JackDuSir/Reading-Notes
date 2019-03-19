#include "stack.h"

//初始化
SeqStack Init_SeqStack()
{
	struct SStack *pp = malloc(sizeof(struct SStack));
	if (NULL == pp)
	{
		return NULL;
	}
	//直接把这块内存初始化为零
	memset(pp, 0, sizeof(struct SStack));
	pp->size = 0;
	return pp;
}
//入栈
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
	//类型转换
	struct SStack *pp = (struct SStack *)stack;
	if (pp->size == MAX)
	{
		return;
	}
	//再栈顶插入，高下标位置
	//在当前最大下表位置插入，就是栈顶
	pp->data[pp->size] = data;
	pp->size++;

}
//出栈
void Pop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct SStack *pp = (struct SStack *)stack;
	//让他的下标减减
	pp->size--;
}
//获得栈顶元素
SeqStack Top_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{ 
		return NULL;
	}

	struct SStack *pp = (struct SStack *)stack;
	 return pp->data[pp->size - 1];

}
//获得栈的大小
int Size_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{
		return -1;
	
	}

	struct SStack *pp = (struct SStack *)stack;
	return pp->size;

}
//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL==stack)
	{
		return;
	}

	free(stack);

}