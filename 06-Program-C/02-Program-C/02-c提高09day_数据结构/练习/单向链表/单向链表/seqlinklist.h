#pragma once 
#ifdef __cplusplus
extern "C"{
#endif 
	//��������˼·
	//���ȴ���һ��������Ϣ�ṹ�壬Ȼ��������ڵ�ṹ��
	//��ʼ������
	//����ڵ�
	//����
	//ÿ����һ���ڵ㣬���Ǿ��¿���һ���ڵ㣬�ڵ�������κΣ�����ֻ�Ǳ������ĵ�ַ
	//���Ƿ��ظ��û���ַ���������Լ�����
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


	//�ڵ���Ϣ
	struct nodemessage
	{
		void *str;
		void *next;
	};
	//������Ϣ
	struct linklistmessage
	{
		struct nodemessage head;
		unsigned int size;
	};
	void *init_link();//��ʼ������������Ϣ�ڵ�
	void insert_link(void *mylink, unsigned int pos, void *data);//����ڵ�
	void delete_link(void *mylink, unsigned int pos);//ɾ���ڵ�
	void fineall_link(void *mylink, void(*print)(void *));///��������
	unsigned int link_node(void *mylink);//�ڵ����
	void findnode_link(void *mylink, unsigned int pos, void(*print)(void *d1));//����λ�ò���




#ifdef __cplusplus
}
#endif 