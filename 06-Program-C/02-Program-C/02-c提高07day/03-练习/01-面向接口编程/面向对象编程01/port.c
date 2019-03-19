#include "port.h"

void init(void ** heand)//初始化数据
{
	if (NULL == heand)
	{
		return;
	}
	struct  data *mydata = malloc(sizeof(struct  data));
	memset(mydata, 0, sizeof(struct data));
	*heand = mydata;
}
void import(void *heand, unsigned char *buf, int len)//输入数据
{
	if (NULL == heand)
	{
		return;
	}
	if (NULL == buf)
	{
		return;
	}

	struct data *temp = (struct data *)heand;
	strncpy(temp->filename, buf, len);
	temp->len = len;
}


void output(void *heand, unsigned char *buf, int *len)//输出数据
{
	if (NULL == heand)
	{
		return;
	}
	if (NULL == buf)
	{
		return;
	}
	if (len == NULL)
	{
		return;
	}

	struct data*temp = (struct data*)heand;
	strncpy(buf, temp->filename, temp->len);
	*len = temp->len;
}
void close(void *heand);//关闭接口

