#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif

#define MAX 1024

	struct SStack
	{
		void *data[MAX];
		int size;

	};

	typedef void * SeqStack;

	//��ʼ��
	SeqStack Init_SeqStack();
	//��ջ
	void Push_SeqStack(SeqStack stack, void *data);
	//��ջ
	void Pop_SeqStack(SeqStack stack);
	//���ջ��Ԫ��
	void *Top_SeqStack(SeqStack stack);
	//���ջ�Ĵ�С
	int Size_SeqStack(SeqStack stack);
	//����ջ
	void Destroy_SeqStack(SeqStack stack);


#ifdef __cplusplus
}
#endif