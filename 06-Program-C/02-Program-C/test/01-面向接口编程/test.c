/*************************************************************************
	> File Name: test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月19日 星期二 14时22分33秒
 ************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CSckImp1.h"

// 初始化
typedef void(*init_CSocketProtocol)(void **handle);
// 发送接口
typedef void(*send_CSocketProtocol)(void *handle, unsigned char *sendData, int sendLen);
// 接收接口
typedef void(*recv_CSocketProtocol)(void *handle, unsigned char *recvData, int *recvLen);
// 关闭接口
typedef void(*close_CSocketProtocol)(void *handle);

// 业务代码
void FrameWork(
		init_CSocketProtocol init,
		send_CSocketProtocol send,
		recv_CSocketProtocol recv,
		close_CSocketProtocol close)
{
	// 初始化链接
	void *handle = NULL;
	init(&handle);

	// 发送数据
	char sendBuf[] = "hello world";
	int sendLen = strlen(sendBuf);
	send(handle, sendBuf, sendLen);

	// 接收数据
	char recvBuf[1024] = { 0 };
	int recvLen = 0;
	recv(handle, recvBuf, &recvLen);
	printf("接收到的数据：%s\n", recvBuf);
	printf("接收到的数据长度：%d\n", recvLen);

	// 关闭链接
	close(handle);
	handle = NULL;
}

void test()
{
	FrameWork(init_CSckImp1, send_CSckImp1, recv_CSckImp1, close_CSckImp1);
}

int main()
{
	test();

	return 0;
}
