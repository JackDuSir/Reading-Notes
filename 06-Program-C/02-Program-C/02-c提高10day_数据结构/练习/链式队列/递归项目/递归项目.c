#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//声明一个结构体，一个左节点，一个右节点
struct BiNode
{
	char arr;//数据域
	struct BiNode *lchicld;//左子树
	struct BiNode *rchicld;//右子树

};


//求叶子节点
void  cuculateLeafNum(struct BiNode *root, int* num)
{
	if (root == NULL)
	{
		return;
	}
	//当他的左右子树为空时就是叶子节点
	if (root->lchicld == NULL && root->rchicld == NULL)
	{
		(*num)++;
	}
	//递归找到左子树叶子节点
	cuculateLeafNum(root->lchicld,num);
	cuculateLeafNum(root->rchicld,num);
}


int  guinode(struct BiNode *root)//求二叉树的深度
{
	if (NULL == root)
	{
		return 0;
	}
	else
	{
	
	int i =	guinode(root->lchicld);
	int j =	guinode(root->rchicld);

	//如果j大于i j+1否i+1

	return j > i ? j + 1 : i + 1;
	//int p = j > i ? j + 1 : i + 1;
	//return p;

	}
}

//销毁二叉树
void freeSpace(struct BiNode * root)
{
	if (NULL == root)
	{
		return;
	}

	freeSpace(root->lchicld);

	freeSpace(root->rchicld);

	printf("%c 被释放！\n", root->arr);
	free(root);
}
//二叉树拷贝
struct BiNode *copyBiTree(struct BiNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}
	//先拷贝左子树
	struct BiNode *lchild = copyBiTree(root->lchicld);
	//拷贝右子树
	struct BiNode *rchild = copyBiTree(root->rchicld);

	struct BiNode *newnode = malloc(sizeof(struct BiNode));
	newnode->rchicld = rchild;
	newnode->lchicld = lchild;
	newnode->arr = root->arr;
	return newnode;

}
//先序遍历二叉树
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

	//先把他拷贝到我们自己的二叉树
	//销毁是销毁我们自己的二叉树

	
	

	//1. 求二叉树的叶子节点数目
	int num = 0;
	//cuculateLeafNum(&nodeA, &num);
	//printf("叶子节点数目:%d\n", num);

	//2. 求二叉树的高度
	int height = guinode(&nodeA);
	printf("树的高度:%d\n", height);

	//int num = 0;
	cuculateLeafNum(&nodeA, &num);
	printf("二叉树的叶子节点数目%d\n",num);
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