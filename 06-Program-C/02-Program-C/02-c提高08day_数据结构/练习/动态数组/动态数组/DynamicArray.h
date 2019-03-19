#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif

	struct DynamicArray
	{
		//数组存储元素的空间的首地址
		void **addr;
		//存储数据的内存中最大能够容纳多少元素
		int capacity;//容量
		//当前存储数据的内容中有多少元素
		int size;//大小
	};

		struct DynamicArray *Init_DynamicArray(int capacity);

		//插入元素，pos代表在第几个元素后面插入
		void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data);

		//调用函数，怎样输出打印数据
		void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *));

		//位置删除
		void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos);
		//按值删除
		void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void *, void *));
		//销毁
		void Destroy_DynamicArray(struct DynamicArray *arr);
#ifdef __cplusplus
}
#endif
	