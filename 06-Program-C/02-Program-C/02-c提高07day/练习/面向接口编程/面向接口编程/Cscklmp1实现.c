#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"CSckImp1.h"

//初始化
typedef void(*init_CSocketProtocol)(void **handle);
//发送接口
typedef void(*send_CSocketProtocol)(void *handle, unsigned char* sendData, int sendLen);
//接收接口
typedef void(*recv_CSocketProtocol)(void *handle, unsigned char* recvData, int* recvLen);
//关闭
typedef void(*close_CSocketProtocol)(void *handle);


//业务代码
void FrameWork(
	//init 出示化函数指针
	init_CSocketProtocol init,
	//send输入函数指针
	send_CSocketProtocol send,
	//recv输出函数指针
	recv_CSocketProtocol recv,
	//关闭接口指针
	close_CSocketProtocol close)

{

	//初始化连接
	void *handle = NULL;
	init(&handle);

	//发送数据
	char buf[] = "hello world!";
	int len = strlen(buf);
	send(handle, buf, len);

	//接收数据
	char recvBuf[1024] = { 0 };
	int recvLen = 0;
	recv(handle, recvBuf, &recvLen);
	printf("接收到的数据:%s\n", recvBuf);
	printf("接收到的数据长度:%d\n", recvLen);

	//关闭连接
	close(handle);
	handle = NULL;

}

void test()
{
	FrameWork(init_CsckImp1, send_CsckImp1, recv_CsckImp1, close_CsckImp1);
}


int main()
{

	test();
	system("pause");
	return EXIT_SUCCESS;
}