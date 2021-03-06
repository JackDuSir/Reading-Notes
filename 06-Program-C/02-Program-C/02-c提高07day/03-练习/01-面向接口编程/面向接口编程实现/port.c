#include"port.h"

struct Port
{
	char data[64];
	int len;
};

void init(void **data)//初始化数据
{
	if (NULL == data)
	{
		return;
	}
	struct Port *myport = malloc(sizeof(struct Port));
	memset(myport, 0, sizeof(struct Port));
	*data = myport;

}
//把接收到的数据存储到新开辟的结构体中
void impotrdata(void *data, void * validdata, int len)//输入数据
{

	if (NULL == data)
	{
		return;
	}
	if (NULL == validdata)
	{
		printf("------\n");
		return;
	}

	struct Port *mydata = (struct Port *)data;

	strncpy(mydata->data, validdata, len);
	mydata->len = len;

}
void dataout(void *data, void *outdata, int *outlen)//输出数据
{
	if (NULL == data)
	{
		return;
	}
	if (NULL == outdata)
	{
		return;
	}
	if (NULL == outlen)
	{
		return;
	}

	struct Port *temp = (struct Port *)data;

	strncpy(outdata, temp->data, temp->len);
	*outlen = temp->len;

}

void close(void *data)//关闭接口
{
	if (NULL == data)
	{
		return;
	}
	free(data);
	data = NULL;

}