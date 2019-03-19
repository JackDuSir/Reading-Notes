#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BiNode
{
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
};

//¶þ²æÊ÷µÝ¹é±éÀú
void recursion(struct BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	//printf("%c ", root->ch);
	//ÏÈÐò±éÀú
	//µÝ¹é±éÀú×ó×ÓÊ÷
	recursion(root->lchild);
	//printf("%c ", root->ch);
	//ÖÐÐò±éÀú
	//µÝ¹é±éÀúÓÒ×ÓÊ÷
	recursion(root->rchild);
	//ºóÐò±éÀú
	printf("%c ", root->ch);

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


	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;
	
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;


	recursion(&nodeA);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}