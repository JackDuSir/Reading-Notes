#define _CRT_SECURE_NO_WARNINGS
#pragma once//防止头文件重复包含，批注

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void init_norm(void **data);//初始化数据
void input_norm(void *data, unsigned char *buf, int effectivelength);//插入数据
void output_norm(void *data, unsigned char *buf, int *effectivelength);//输出数据
void colse_norm(void *data);//关闭接口