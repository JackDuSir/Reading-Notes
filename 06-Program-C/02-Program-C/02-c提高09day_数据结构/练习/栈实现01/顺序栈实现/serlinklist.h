#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
//1.˳��ջ�Ľṹ�壬����ջ����Ϣ
//2.ջ�ĳ�ʼ���������ڴ�
//3.ѹջ
//4.��ջ
//5.���ջ��
	//���ջ�Ĵ�С
//6.�ж����
//7.����

	struct SStack
	{
		//void *�ɴ���κ����͵�ַ
		void *data[MAX];
		int size;//ջ��Ԫ�صĸ���
	};

	void *init_seqstak();//��ʼ��ջ
	void push_seqstack(void *stack, void *data);//��ջ
	void pop_seqstack(void *stack);//��ջ
	void *top(void *stack);//���ջ��
	int size_seqstack(void *stack);//���ջ�Ĵ�С
	void Destory_seqstack(void* stack);//����ջ

	
#ifdef __cplusplus
}
#endif