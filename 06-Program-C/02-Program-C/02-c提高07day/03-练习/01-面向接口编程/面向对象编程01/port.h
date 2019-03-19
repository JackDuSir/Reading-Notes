#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
	char filename[20];
	int len;

};

void init(void ** heand);//初始化数据
void import(void *heand, unsigned char *buf, int len);//输入数据
void output(void *heand, unsigned char *buf, int *len);//输出数据
void close(void *heand);//关闭接口
