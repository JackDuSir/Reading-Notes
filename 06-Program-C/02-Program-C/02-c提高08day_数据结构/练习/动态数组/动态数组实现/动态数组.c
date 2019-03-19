#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DynamicArray
{
	void **addr;
	int capacity;
	int size;
};
//初始化数据组
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

//传入结构体，传入插入位置，传入数据，
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
		//内存不够直接,直接重新开辟一块内存
		int newcapacity = arr->capacity * 2;
		void **newspace = malloc(sizeof(void *)*newcapacity);
		//把原来的内存中的内容拷贝到新的内存中
		memcpy(newcapacity, arr->addr, sizeof(void *)*arr->capacity);
		//释放原来的内存
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