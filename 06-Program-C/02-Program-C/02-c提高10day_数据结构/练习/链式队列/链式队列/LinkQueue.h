#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif



	//�ڵ���Ϣ
	struct queuenode
	{
		struct queuenode *next;

	};


	//������Ϣ
	struct queuelink
	{
		struct queuenode head;
		int size;
		struct queuenode * back;
	};


	void * init_queuelink();//��ʼ������
	void push_queuelink(void *Qlink, void *data);//��������
	void pop_queuelink(void *Qlink);//����
	void *top_queuelink(void *Qlink);//������
	int Size_queuelink(void*Qlink);//��С
	void Destroy_queuelink(void*Qlink);







#ifdef __cplusplus
}
#endif