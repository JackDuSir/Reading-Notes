#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//需要两个结构体
	//一个节点结构体
	//一个是节点信息结构体
	//初始化节点信息结构体
	//插入节点
	//根据节点位置查找节点
	//根据值位置查找节点

	
	//LinkList就带表了void *
	typedef void * LinkList;
	//
	typedef void(*FOREACH)(void *);
	typedef int(*COMPARE)(void *,void *);

	LinkList Init_LinkList();//初始化链表
	void Insert_LinkList(LinkList list, int pos, void *data);//插入节点
	void Foreach_LinkList(LinkList list, FOREACH myforeach);//遍历节点
	
	void RemoveByPos_LinkList(LinkList list, int pos);//按位置删除
	
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);//按值删除
	
	void Clear_LinkList(LinkList list);//清空链表
	
	int Size_LinkList(LinkList list);//大小
	
	void Destroy_LinkList(LinkList list);//销毁链表
	


#ifdef __cplusplus
}
#endif