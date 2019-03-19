#include"linklist.h"

vo init()//��ʼ��
{
	struct Stru *mystru = malloc(sizeof(struct Stru));
	if (NULL == mystru)
	{
		return NULL;
	}

	mystru->header.stru = NULL;
	mystru->size = 0;
	return mystru;
}
void push(vo content, vo data)//����
{
	//��ʽջ����Ҫ�ж����
	if (NULL == content)
	{
		return;
	}
	if (NULL==data)
	{
		return;
	}
	struct Stru *mycontent = (struct Stru *)content;
	struct structure *mydata = (struct structure *)data;
	//mydata = mycontent->header.stru;
	//
	mydata->stru = mycontent->header.stru;
	mycontent->header.stru = mydata;
	//ÿ����һ�ξ�����һ��
	mycontent->size++;

}
void pop(vo content)//����
{
	if (NULL == content)
	{
		return;
	}

	struct Stru *mycontent = (struct Stru *)content;
	if (mycontent->size == 0)
	{
		return;
	}
	struct structure *newnode = mycontent->header.stru;
	mycontent->header.stru = newnode->stru;
	mycontent->size--;
}

 vo top(vo content)//���ջ��
{
	if (NULL == content)
	{
		return NULL;
	}
	
	struct Stru *mycontent = (struct Stru *)content;

	if (mycontent->size == 0)
	{
		return NULL;
	}
	//���ؽṹ��ǰ�ĸ��ֽڣ���Ҫ�û��Լ���������
	return mycontent->header.stru;
}


int statcksize(vo content)//վ�Ĵ�С
{
	if (NULL == content)
	{
		return -1;
	}
	struct Stru * mycontent = (struct Stru *)content;
	return mycontent->size;

}
void destroy(vo content)//����
{
	if (NULL == content)
	{
		return;
	}

	free(content);
	content = NULL;
}