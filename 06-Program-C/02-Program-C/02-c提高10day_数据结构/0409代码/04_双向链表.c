#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
	int data;
	struct _node *pre;
	struct _node *next;
}Node;

void createList(Node **head)
{

	Node * node = (Node *)malloc(sizeof(Node));
	node->pre = NULL;
	node->next = NULL;
	node->data = -1;
	int num = 0;

	printf("请输入数据,'q' 键结束输入\n");
	scanf("%d", &num);
	//链表为空,即只有头结点时,插入
	if (node->next == NULL) {
		Node * newNode = malloc(sizeof(Node));
		newNode->data = num;
		node->next = newNode;
		newNode->next = NULL;
		newNode->pre = NULL;
	}
	Node * pCur = node->next;
	Node * pNext = pCur->next;
	// 尾插法,初始化链表
	while (scanf("%d", &num) > 0) {
		Node * newNode = malloc(sizeof(Node));
		newNode->data = num;

		pCur->next = newNode;
		newNode->next = NULL;
		newNode->pre = pCur;

		//辅助指针后移
		pCur = pCur->next;
	}
	*head = node;
}

/*
函数功能:在第一个节点处插入数据
函数参数:
函数返回值: 
*/
void frontInsertListNode(Node *head, int data)
{
	if (NULL == head) {
		return;
	}

	Node * newNode = malloc(sizeof(Node));
	newNode->data = data;
	//链表为空,即只有头结点时,插入
	if (head->next == NULL) {
		head->next = newNode;
		newNode->next = NULL;
		newNode->pre = NULL;
	}

	newNode->next = head->next;
	newNode->pre = NULL;
	newNode->next->pre = newNode;
	head->next = newNode;
}

/*
函数功能:在指定数据后添加节点
函数参数:
函数返回值: 
*/
void insertListNodeByValue(Node *head,int value,  int data)
{
	if (NULL == head) {
		return;
	}

	Node * newNode = malloc(sizeof(Node));
	newNode->data = data;
	//链表为空,即只有头结点时,数据直接插入
	if (head->next == NULL) {
		head->next = newNode;
		newNode->next = NULL;
		newNode->pre = NULL;
	}
	Node *pCur = head->next;
	Node *pPre = pCur->pre;
	while (pCur != NULL){
		if (pCur->data != value) {
			pCur = pCur->next;
			pPre = pCur->pre;
		}
		else {
			break;
		}
	}
	// 没有找到value 的值,跳出while循环,此时将数据插入到尾部,即ppPre指向尾节点
	if (NULL == pCur) {
		pCur = pPre;
		pCur->next = newNode;
		newNode->next = NULL;
		newNode->pre = pCur;
	}
	else {	//找到value的值,此时pCur指向此数据
		newNode->next = pCur->next;
		newNode->pre = pCur;
		pCur->next = newNode;
		newNode->next->pre = newNode;
	}
}


void deleteListNodeByValue(Node * head, int value)
{
	if (NULL == head) {
		return;
	}

	Node *pCur = head->next;
	Node *pPre = pCur->pre;

	while (pCur != NULL) {
		if (pCur->data != value) {
			pCur = pCur->next;
			pPre = pCur->pre;
		}
		else {
			break;
		}
	}
	//判断删除节点是否为尾节点
	if (NULL == pCur) {
		pCur = pPre;
		pPre = pCur->pre;

		pPre->next = NULL;
		pCur->pre = NULL;
		free(pCur);
		pCur = NULL;
	}

	//其他删除情况,即pCur 指向的数据
	pPre->next = pCur->next;
	pCur->next->pre = pPre;
	free(pCur);
	pCur = NULL;

}

/*
函数功能:销毁链表
函数参数:
函数返回值: 
*/
void destoryList(Node * head)
{
	if (NULL == head) {
		return;
	}
	Node * pCur = head->next;
	while (head->next != NULL) {
		free(head);
		head = pCur;
		pCur = pCur->next;
	}
	
}

/*
函数功能:正向遍历链表
函数参数:
函数返回值: 
*/
void printList(Node * head)
{
	if (NULL == head) {
		return;
	}
	Node *pCur = head->next;
	while (pCur != NULL)
	{
		printf("%d\t", pCur->data);
		pCur = pCur->next;
	}
}

/*
函数功能:反向遍历链表
函数参数:
函数返回值: 
*/
void RPrintList(Node * head)
{
	if (NULL == head) {
		return;
	}

	Node * pCur = head;
	//找到尾节点
	while (pCur->next != NULL) {
		pCur = pCur->next;
	}


	//反向打印
	while (pCur != NULL) {
		printf("%d\t", pCur->data);
		pCur = pCur->pre;
	}
}

void test()
{
	Node *head = NULL;

	//3、1、10、7、6、5
	createList(&head);
	printf("正向打印链表\n");
	printList(head);
	printf("\n正向打印链表\n");
	RPrintList(head);

	frontInsertListNode(head, 21);
	printf("\n插入数据21后,正向打印链表\n");
	printList(head);
	printf("\n插入数据21后,反向打印链表\n");
	RPrintList(head);

	printf("\n在数据3 后边插入数据9\n");
	insertListNodeByValue(head, 3, 9);
	printList(head);

	printf("\n删除节点为6 的数据\n");
	deleteListNodeByValue(head, 6);
	printList(head);

	destoryList(head);
}
int main(void)
{
	test();
	printf("\n");
	return 0;
}