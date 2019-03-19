#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����һ���ṹ�壬һ����ڵ㣬һ���ҽڵ�
struct BiNode
{
	char arr;//������
	struct BiNode *lchicld;//������
	struct BiNode *rchicld;//������

};


//��Ҷ�ӽڵ�
void  cuculateLeafNum(struct BiNode *root, int* num)
{
	if (root == NULL)
	{
		return;
	}
	//��������������Ϊ��ʱ����Ҷ�ӽڵ�
	if (root->lchicld == NULL && root->rchicld == NULL)
	{
		(*num)++;
	}
	//�ݹ��ҵ�������Ҷ�ӽڵ�
	cuculateLeafNum(root->lchicld,num);
	cuculateLeafNum(root->rchicld,num);
}


int  guinode(struct BiNode *root)//������������
{
	if (NULL == root)
	{
		return 0;
	}
	else
	{
	
	int i =	guinode(root->lchicld);
	int j =	guinode(root->rchicld);

	//���j����i j+1��i+1

	return j > i ? j + 1 : i + 1;
	//int p = j > i ? j + 1 : i + 1;
	//return p;

	}
}

//���ٶ�����
void freeSpace(struct BiNode * root)
{
	if (NULL == root)
	{
		return;
	}

	freeSpace(root->lchicld);

	freeSpace(root->rchicld);

	printf("%c ���ͷţ�\n", root->arr);
	free(root);
}
//����������
struct BiNode *copyBiTree(struct BiNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}
	//�ȿ���������
	struct BiNode *lchild = copyBiTree(root->lchicld);
	//����������
	struct BiNode *rchild = copyBiTree(root->rchicld);

	struct BiNode *newnode = malloc(sizeof(struct BiNode));
	newnode->rchicld = rchild;
	newnode->lchicld = lchild;
	newnode->arr = root->arr;
	return newnode;

}
//�������������
void showBiTree(struct BiNode *root)
{
	if (NULL == root)
	{
		return;
	}
	
	printf("%c ", root->arr);
	showBiTree(root->lchicld);
	showBiTree(root->rchicld);
}



void test()
{
	
	struct BiNode nodeA = { 'A', NULL, NULL };
	struct BiNode nodeB = { 'B', NULL, NULL };
	struct BiNode nodeC = { 'C', NULL, NULL };
	struct BiNode nodeD = { 'D', NULL, NULL };
	struct BiNode nodeE = { 'E', NULL, NULL };
	struct BiNode nodeF = { 'F', NULL, NULL };
	struct BiNode nodeG = { 'G', NULL, NULL };
	struct BiNode nodeH = { 'H', NULL, NULL };
	struct BiNode nodeQ = { 'Q', NULL, NULL };


	nodeA.lchicld = &nodeB;
	nodeA.rchicld = &nodeF;

	nodeB.rchicld = &nodeC;

	nodeC.lchicld = &nodeD;
	nodeC.rchicld = &nodeE;

	nodeF.rchicld = &nodeG;

	nodeG.lchicld = &nodeH;

	nodeG.rchicld = &nodeQ;

	//�Ȱ��������������Լ��Ķ�����
	//���������������Լ��Ķ�����

	
	

	//1. ���������Ҷ�ӽڵ���Ŀ
	int num = 0;
	//cuculateLeafNum(&nodeA, &num);
	//printf("Ҷ�ӽڵ���Ŀ:%d\n", num);

	//2. ��������ĸ߶�
	int height = guinode(&nodeA);
	printf("���ĸ߶�:%d\n", height);

	//int num = 0;
	cuculateLeafNum(&nodeA, &num);
	printf("��������Ҷ�ӽڵ���Ŀ%d\n",num);
	showBiTree(&nodeA);
	printf("\n");
	struct BiNode * root = copyBiTree(&nodeA);
	showBiTree(root);
	printf("\n");
	freeSpace(root);
}





int main()
{

	test();

	system("pause");

}