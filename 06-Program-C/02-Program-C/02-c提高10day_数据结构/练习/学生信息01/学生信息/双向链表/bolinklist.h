#pragma once 
#include <stdio.h>
#include<stdlib.h>
#include<string.h>



//�ڵ�
struct LinklistNode
{
	void *data;
	struct LinklistNode *haed;
	struct LinklistNode* next;
};
//������Ϣ
struct LinklistMessage
{
	struct LinklistNode linkhead;
	int size;
};

typedef struct LinklistNode Node;
typedef struct LinklistMessage Link;

//��ʼ������
void *InitLink();

//�������� ����λ��
void InsertNode(void *linkhead, int pos, void *data);
//ɾ������ ����λ��
void DeleteNode(void *linkhead, int pos);
//��������
void show(void *linkhead,void(*print)(void *));
//�������
void revshow(void *linkhead, void(*print)(void *));
//��������
void deslinklist(void *linkhead);
//��ӡ�ڵ����
void NodeAmount(void *linkhead);
//��ֵ����
void PriceSeek(void *linkhead, void* data);