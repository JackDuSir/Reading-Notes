/*************************************************************************
	> File Name: CSckImp1.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月19日 星期二 14时39分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"CSckImp1.h"

struct Info
{
	char data[1024];
	int len;
};

// 初始化
void init_CSckImp1(void **handle)
{
	if (NULL == handle)
		return;

	struct Info *info = malloc(sizeof(struct Info));
	memset(info, 0, sizeof(struct Info));

	*handle = info;
}

// 发送接口
void send_CSckImp1(void *handle, unsigned char *sendData, int sendLen)
{
	if (NULL == handle)
		return;

	if (NULL == sendData)
		return;

	struct Info *info = (struct Info*)handle;

	printf("sendData=%s sendLen=%d\n", sendData, sendLen);
	strncpy(info->data, sendData, sendLen);
	info->len = sendLen;
	printf("info->data=%d info->len=%d\n", info->data, info->len);
	printf("%s\n", __FUNCTION__);
}

// 接收接口
void recv_CSckImp1(void *handle, unsigned char *recvData, int *recvLen)
{
	if (NULL == handle)
		return;

	if (NULL == recvData)
		return;

	if (NULL == recvLen)
		return;

	struct Info *info = (struct Info*)handle;
	strncpy(recvData, info->data, info->len);
	*recvLen = info->len;
	printf("recvData=%s recvLen=%d\n", recvData, recvLen);
	printf("%s\n", __FUNCTION__);
}

// 关闭接口
void close_CSckImp1(void *handle)
{
	if (NULL == handle)
		return;

	free(handle);
	handle = NULL;
}

