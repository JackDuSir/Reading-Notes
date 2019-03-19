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

	printf("����������,'q' ����������\n");
	scanf("%d", &num);
	//����Ϊ��,��ֻ��ͷ���ʱ,����
	if (node->next == NULL) {
		Node * newNode = malloc(sizeof(Node));
		newNode->data = num;
		node->next = newNode;
		newNode->next = NULL;
		newNode->pre = NULL;
	}
	Node * pCur = node->next;
	Node * pNext = pCur->next;
	// β�巨,��ʼ������
	while (scanf("%d", &num) > 0) {
		Node * newNode = malloc(sizeof(Node));
		newNode->data = num;

		pCur->next = newNode;
		newNode->next = NULL;
		newNode->pre = pCur;

		//����ָ�����
		pCur = pCur->next;
	}
	*head = node;
}

/*
��������:�ڵ�һ���ڵ㴦��������
��������:
��������ֵ: 
*/
void frontInsertListNode(Node *head, int data)
{
	if (NULL == head) {
		return;
	}

	Node * newNode = malloc(sizeof(Node));
	newNode->data = data;
	//����Ϊ��,��ֻ��ͷ���ʱ,����
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
��������:��ָ�����ݺ���ӽڵ�
��������:
��������ֵ: 
*/
void insertListNodeByValue(Node *head,int value,  int data)
{
	if (NULL == head) {
		return;
	}

	Node * newNode = malloc(sizeof(Node));
	newNode->data = data;
	//����Ϊ��,��ֻ��ͷ���ʱ,����ֱ�Ӳ���
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
	// û���ҵ�value ��ֵ,����whileѭ��,��ʱ�����ݲ��뵽β��,��ppPreָ��β�ڵ�
	if (NULL == pCur) {
		pCur = pPre;
		pCur->next = newNode;
		newNode->next = NULL;
		newNode->pre = pCur;
	}
	else {	//�ҵ�value��ֵ,��ʱpCurָ�������
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
	//�ж�ɾ���ڵ��Ƿ�Ϊβ�ڵ�
	if (NULL == pCur) {
		pCur = pPre;
		pPre = pCur->pre;

		pPre->next = NULL;
		pCur->pre = NULL;
		free(pCur);
		pCur = NULL;
	}

	//����ɾ�����,��pCur ָ�������
	pPre->next = pCur->next;
	pCur->next->pre = pPre;
	free(pCur);
	pCur = NULL;

}

/*
��������:��������
��������:
��������ֵ: 
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
��������:�����������
��������:
��������ֵ: 
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
��������:�����������
��������:
��������ֵ: 
*/
void RPrintList(Node * head)
{
	if (NULL == head) {
		return;
	}

	Node * pCur = head;
	//�ҵ�β�ڵ�
	while (pCur->next != NULL) {
		pCur = pCur->next;
	}


	//�����ӡ
	while (pCur != NULL) {
		printf("%d\t", pCur->data);
		pCur = pCur->pre;
	}
}

void test()
{
	Node *head = NULL;

	//3��1��10��7��6��5
	createList(&head);
	printf("�����ӡ����\n");
	printList(head);
	printf("\n�����ӡ����\n");
	RPrintList(head);

	frontInsertListNode(head, 21);
	printf("\n��������21��,�����ӡ����\n");
	printList(head);
	printf("\n��������21��,�����ӡ����\n");
	RPrintList(head);

	printf("\n������3 ��߲�������9\n");
	insertListNodeByValue(head, 3, 9);
	printList(head);

	printf("\nɾ���ڵ�Ϊ6 ������\n");
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