#define _CRT_SECURE_NO_WARNINGS
#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void init(void *data);//初始化数据
void impotrdata(void *data, void *validdata, int len);//输入数据
void dataout(void *data, void *outdata, int *outlen);//输出数据
void close(void *data);//关闭接口
