#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DynamicArray
{
	void **addr;
	int capacity;
	int size;
};
//��ʼ��������
struct DynamincArray *Init_DynamicArray(int capacity)
{

	if (capacity < 0)
	{
		return NULL;
	}
	struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	arr->capacity = capacity;
	arr->size = 0;
	arr->addr = malloc(sizeof(void *)*arr->capacity);
	return arr;
}

//����ṹ�壬�������λ�ã��������ݣ�
void Inser_DynamicArray9(struct DynamicArray *arr, int pos, void*data)
{

	if (NULL == arr)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (pos<0 || pos>arr->size)
	{
		pos = arr->size;
	}

	if (arr->size >= arr->capacity)
	{
		//�ڴ治��ֱ��,ֱ�����¿���һ���ڴ�
		int newcapacity = arr->capacity * 2;
		void **newspace = malloc(sizeof(void *)*newcapacity);
		//��ԭ�����ڴ��е����ݿ������µ��ڴ���
		memcpy(newcapacity, arr->addr, sizeof(void *)*arr->capacity);
		//�ͷ�ԭ�����ڴ�
		free(arr->addr);
		//
		arr->addr = newspace;
		arr->capacity = newspace;
	}

	for (int i = arr->size; i > pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}
	arr->addr[pos] = data;
	arr->size++;

}


void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		return;
	}
	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}

}