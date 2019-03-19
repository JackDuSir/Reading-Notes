#include"linklist.h"

vo init()//初始化
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
void push(vo content, vo data)//插入
{
	//链式栈不需要判断溢出
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
	//每插入一次就增加一次
	mycontent->size++;

}
void pop(vo content)//弹出
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

 vo top(vo content)//获得栈顶
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
	//返回结构体前四个字节，需要用户自己解析类型
	return mycontent->header.stru;
}


int statcksize(vo content)//站的大小
{
	if (NULL == content)
	{
		return -1;
	}
	struct Stru * mycontent = (struct Stru *)content;
	return mycontent->size;

}
void destroy(vo content)//销毁
{
	if (NULL == content)
	{
		return;
	}

	free(content);
	content = NULL;
}