#pragma once 
#ifdef __cplusplus
extern "C"{
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//1.����һ���ṹ�����������Ϣ
	struct myarray
	{
		//������׵�ַ
		void **arrhead;
		//���鳤��
		int lenin;
		//�����±�
		int size;
	};


	//��ʼ��������
	void * initarr(int length);//��ʼ�����飬����һ���ռ䷵�ص�ַ
	//��������
	void insertarr(void *array,int pos, void *data);//��������
	//ɾ������
	void deletedata(void *array, int pos);//����λ��ɾ��
	//��������
	void show(void* array, void(*comprint)(void *));//��ʾ����
	//��������
	void seek(void *array, void* data, int(*compare)(void *, void *));//����ֵ��������
	//����λ�ò���
	void fine(void *array, int pos, void(*print)(void *d1));
	//��������
	void emptyarr(void *array);






#ifdef __cplusplus
}
#endif
