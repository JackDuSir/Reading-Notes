#pragma once
#ifdef __cplusplus
extern "C"{
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	struct structure
	{
		struct structure *stru;

	};

	struct Stru
	{
		struct structure header;
		int size;
	};

	typedef void * vo;
	vo init();//��ʼ��
	void push(vo content, vo data);//����
	void pop(vo content);//����
	int statcksize(vo content);//վ�Ĵ�С
	vo top(vo content);//��ȡջ��
	void destroy(vo content);//����





#ifdef __cplusplus
}
#endif