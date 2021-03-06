#include "CsckImp1.h"

struct  Info
{
	char data[1024];
	int len;
};


//初始化
void init_CsckImp1(void **handle)
{
	if (NULL == handle)
	{
		return;
	}
	//开辟空间，并初始化
	struct Info *infodata = malloc(sizeof(struct Info));
	memset(infodata, 0, sizeof(struct Info));
	*handle = infodata;
}
//发送接口
void send_CsckImp1(void *handle, unsigned char* sendData, int sendLen)
{
	if (NULL == handle)
	{
		return;
	}
	if (NULL == sendData)
	{
		return;
	}

	struct  Info *temp = (struct  Info *)handle;
	strncpy(temp->data, sendData, sendLen);
	temp->len = sendLen;
}
//接收接口第一个参数是结构体，第二个参数是用户定义内存，第三参数是内容大小
void recv_CsckImp1(void *handle, unsigned char *recvData, int* recvLen)
{	//传入的是void 类型需要转换为输入的类型
	
	if (NULL == handle)
	{
		return;
	}
	if (NULL == recvData)
	{
		return;
	}

	struct  Info *temp = (struct  Info *)handle;
	strncpy(recvData, temp->data, temp->len);
	*recvLen = temp->len;
}
//关闭接口
void close_CsckImp1(void *handle)
{
	
	if (NULL == handle)
	{
		return;
	}

	free(handle);
	handle = NULL;
}