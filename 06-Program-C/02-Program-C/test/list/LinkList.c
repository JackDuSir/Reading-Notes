/*************************************************************************
	> File Name: LinkList.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月19日 星期二 11时30分40秒
 ************************************************************************/

#include<stdio.h>
#include"LinkList.h"

// 初始化链表
struct LinkNode *Init_LinkList()
{
	
}

// 在值为oldval的后面插入一个新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval);

// 删除值为val的节点
void RemoveByValue_LinkList(struct LinkNode *header, int delValue);

// 遍历
void Foreach_LinkList(struct LinkNode *header);

// 销毁
void Destroy_LinkList(struct LinkNode *header);

// 清空
void Clear_LinkList(struct LinkNode *header);


