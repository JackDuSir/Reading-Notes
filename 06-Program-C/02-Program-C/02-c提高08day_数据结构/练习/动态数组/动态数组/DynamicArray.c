#include"DynamicArray.h"

//1.先把需要的数据信息结构定义下来
//初始化数组
//返回一个struct DynamicArray *指针
struct DynamicArray *Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	//开辟一个struct DynamicArray *结构体
	struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	//arr->capacity给他赋值我们传入的值
	arr->capacity = capacity;
	//给arr->addr分配我们传入的值得内存
	//给arr结构体中的addr分配内存，它里面存储的是指针，就是数据地址
	arr->addr = malloc(sizeof(void *) * arr->capacity);
	//开始下标为0，size为零
	arr->size = 0;
	return arr;
}

//插入元素，pos代表在第几个元素后面插入
void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data)
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (pos<0 || pos>arr->capacity)
	{
		pos = arr->size;
	}
	
	if (arr->size > arr->capacity)
	{
		int newcapacity = arr->capacity * 2;
		void **newpace = malloc(sizeof(void *)*newcapacity);

		memcpy(newpace, arr->addr, sizeof(void *)*arr->capacity);

		free(arr->addr);
		arr->addr = newpace;
		arr->capacity = newcapacity;
	}
	for (int i = arr->size; i > pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}
	arr->addr[pos] = data;
	arr->size++;
}

//调用函数，怎样输出打印数据
void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *))
{
	
	if (NULL == arr)
	{
		return;
	}
	if (NULL == _callback)
	{
		return;
	}
	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}
}
//位置删除
void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos)
{
	if (NULL == arr)
	{
		return;
	}
	if (pos<0 || pos > arr->size)

	{
		return;
	}
	for (int i = pos; i < arr->size-1; ++i)
	{
		arr->addr[i] = arr->addr[i + 1];
	}
	arr->size--;
}

//按值删除
void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void *, void *))
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL==data)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	for (int i = 0; i < arr->size; ++i)
	{
		if (compare(arr->addr[i], data))
		{
			RemoveByPos_DynamicArray(arr, i);
			break;
		}
	}
}
//销毁
void Destroy_DynamicArray(struct DynamicArray *arr)
{
	if (NULL == arr)
	{
		return;
	}
	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}
	free(arr);
	arr = NULL;

}