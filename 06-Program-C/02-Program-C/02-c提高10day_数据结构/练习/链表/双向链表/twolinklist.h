#include<stdio.h>
#include<string.h>
#include<stdlib.h>



struct node
{
	void *data;
	struct node *head;
	struct node *back;
};


struct linklist
{
	struct node headnod;
	int size;
};


void *init();//��ʼ��
void inser(void *linklist, int pos, void *data);//����
void  show(void *linklist, void(*print)(void *));//�����ӡ
void deletenode(void *linklist, int pos);//����λ��ɾ��
void reverseshow(void *linklist, void(*print)(void *));//�����ӡ
void destroy(void *linklist);//����