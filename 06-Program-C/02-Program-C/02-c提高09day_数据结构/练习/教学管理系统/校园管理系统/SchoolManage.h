#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodeMessage
{
	void *data;
	struct nodeMessage *next;
};

struct linkMessage
{
	struct nodeMessage head;
	int size;
};

typedef struct nodeMessage * nodemessage;
typedef struct linkMessage * linkmessage;

void*init();//��ʼ��
void insertnode(void *link, int pos, void *data);//��������
void deletenode(void *link, int pos);//ɾ���ڵ�
void seeknode(void *link, int pos, void(*print)(void *));//���ҽڵ�
void alternode(void *link, int pos);//�޸Ľڵ�
void shownode(void *link, void(*print)(void *));//��ӡ�ڵ�