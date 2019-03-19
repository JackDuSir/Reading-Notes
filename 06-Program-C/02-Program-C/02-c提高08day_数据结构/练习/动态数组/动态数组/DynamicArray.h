#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif

	struct DynamicArray
	{
		//����洢Ԫ�صĿռ���׵�ַ
		void **addr;
		//�洢���ݵ��ڴ�������ܹ����ɶ���Ԫ��
		int capacity;//����
		//��ǰ�洢���ݵ��������ж���Ԫ��
		int size;//��С
	};

		struct DynamicArray *Init_DynamicArray(int capacity);

		//����Ԫ�أ�pos�����ڵڼ���Ԫ�غ������
		void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data);

		//���ú��������������ӡ����
		void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *));

		//λ��ɾ��
		void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos);
		//��ֵɾ��
		void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void *, void *));
		//����
		void Destroy_DynamicArray(struct DynamicArray *arr);
#ifdef __cplusplus
}
#endif
	