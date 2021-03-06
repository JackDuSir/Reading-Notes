#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
struct linklistnode
{
	int data;
	struct linklistnode  *next;
};
typedef struct linklistnode node;


node * init(node *phead);//初始化链表
node* addback(node *phead, int key);//尾部插入
node * addhead(node *phead, int key);//头插

node *alter(node *phead, int outdata, int newdata);//在outdat后插入数据
void showlinklist(node *phead);//打印数据
node *delete(node *phead, int outdata);//删除节点
node *rev(node *phead);//反转链表
void mergelinklist(node *p1, node *p2);//合并链表
int guiallnode(node *phead);//递归统计节点
node* location(node *phead, unsigned int k);//查找倒数第k个节点
node *middlenode(node *phead);//查找中间节点
