#pragma once 
#ifdef __cplusplus
extern "C"{
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//1.定义一个结构体包含数组信息
	struct myarray
	{
		//数组的首地址
		void **arrhead;
		//数组长度
		int lenin;
		//数组下标
		int size;
	};


	//初始化化数组
	void * initarr(int length);//初始化数组，开辟一个空间返回地址
	//插入数据
	void insertarr(void *array,int pos, void *data);//插入数据
	//删除数据
	void deletedata(void *array, int pos);//根据位置删除
	//遍历数据
	void show(void* array, void(*comprint)(void *));//显示数据
	//查找数据
	void seek(void *array, void* data, int(*compare)(void *, void *));//根据值查找数据
	//根据位置查找
	void fine(void *array, int pos, void(*print)(void *d1));
	//销毁数组
	void emptyarr(void *array);






#ifdef __cplusplus
}
#endif
