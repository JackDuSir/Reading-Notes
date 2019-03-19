#pragma once 
#ifdef __cplusplus
extern "C"{
#endif 
	//单向链表思路
	//首先创建一个链表信息结构体，然后是链表节点结构体
	//初始化链表
	//插入节点
	//遍历
	//每插入一个节点，我们就新开辟一个节点，节点可以是任何，我们只是保存它的地址
	//我们返回给用户地址，让他们自己解析
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


	//节点信息
	struct nodemessage
	{
		void *str;
		void *next;
	};
	//链表信息
	struct linklistmessage
	{
		struct nodemessage head;
		unsigned int size;
	};
	void *init_link();//初始化链表，链表信息节点
	void insert_link(void *mylink, unsigned int pos, void *data);//插入节点
	void delete_link(void *mylink, unsigned int pos);//删除节点
	void fineall_link(void *mylink, void(*print)(void *));///遍历链表
	unsigned int link_node(void *mylink);//节点个数
	void findnode_link(void *mylink, unsigned int pos, void(*print)(void *d1));//按照位置查找




#ifdef __cplusplus
}
#endif 