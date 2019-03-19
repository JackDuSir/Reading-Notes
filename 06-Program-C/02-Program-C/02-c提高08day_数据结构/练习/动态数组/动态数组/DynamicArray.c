#include"DynamicArray.h"

//1.�Ȱ���Ҫ��������Ϣ�ṹ��������
//��ʼ������
//����һ��struct DynamicArray *ָ��
struct DynamicArray *Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	//����һ��struct DynamicArray *�ṹ��
	struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	//arr->capacity������ֵ���Ǵ����ֵ
	arr->capacity = capacity;
	//��arr->addr�������Ǵ����ֵ���ڴ�
	//��arr�ṹ���е�addr�����ڴ棬������洢����ָ�룬�������ݵ�ַ
	arr->addr = malloc(sizeof(void *) * arr->capacity);
	//��ʼ�±�Ϊ0��sizeΪ��
	arr->size = 0;
	return arr;
}

//����Ԫ�أ�pos�����ڵڼ���Ԫ�غ������
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

//���ú��������������ӡ����
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
//λ��ɾ��
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

//��ֵɾ��
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
//����
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