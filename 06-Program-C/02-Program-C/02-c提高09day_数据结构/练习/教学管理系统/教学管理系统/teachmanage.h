#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifdef __cplusplus
extern "C"{
#endif 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

	
	struct site
	{
		struct site *next;
	};

	struct teacher
	{
		struct site head;
		unsigned int size;
	};

	void  init_data(void ** teacher);//��ʼ������
	void insert_data(void *linklins, unsigned int pos, void *data);//��������
	void delete_data(void *linklins, unsigned int pos);//����λ��ɾ������
	void find_data(void *linklins, unsigned int pos, void(*print)(void *));//����
	void findall_data(void *linklins, void(*print)(void *));//����
	void alter_data(void *linklins, unsigned int pos, void *data);//�޸�
	void pricefine_data(void *linklins, void *data, int(*compare)(void *, void*), void(*prin)(void *));//����ֵ����



#ifdef __cplusplus
}
#endif 