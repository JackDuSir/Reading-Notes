/*************************************************************************
	> File Name: CSckImp1.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月19日 星期二 14时36分12秒
 ************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 初始化
void init_CSckImp1(void **handle);
// 发送接口
void send_CSckImp1(void *handle, unsigned char *sendData, int sendLen);
// 接收接口
void recv_CSckImp1(void *handle, unsigned char *recvData, int *recvLen);
// 关闭接口
void close_CSckImp1(void *handle);


