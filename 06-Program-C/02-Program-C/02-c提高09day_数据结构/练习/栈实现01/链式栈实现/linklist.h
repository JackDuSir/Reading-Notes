#pragma once
#ifdef __cplusplus
extern "C"{
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	struct structure
	{
		struct structure *stru;

	};

	struct Stru
	{
		struct structure header;
		int size;
	};

	typedef void * vo;
	vo init();//初始化
	void push(vo content, vo data);//插入
	void pop(vo content);//弹出
	int statcksize(vo content);//站的大小
	vo top(vo content);//获取栈顶
	void destroy(vo content);//销毁





#ifdef __cplusplus
}
#endif