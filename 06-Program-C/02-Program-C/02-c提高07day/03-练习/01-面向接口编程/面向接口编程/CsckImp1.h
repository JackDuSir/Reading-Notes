#define _CRT_SECURE_NO_WARNINGS
#pragma once//批注,这个文件之编译一次，防止重复包含

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//初始化
void init_CsckImp1(void **handle);
//发送接口
void send_CsckImp1(void *handle, unsigned char* sendData, int sendLen);
//接收接口
void recv_CsckImp1(void *handle, unsigned char *recvData, int *recvLen);
//关闭接口
void close_CsckImp1(void *handle);
