#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	void* data;
	struct node *next;

};

struct linklistinf
{
	struct node head;
	int size;
};



void *init();//≥ı ºªØ
void inser(void *linkls, int pos, void *data);
void show(void *linkls,void(*print)(void *));
void destroy(void *linklist);
