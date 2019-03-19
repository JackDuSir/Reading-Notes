#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>//������������
#include"SeqStack.h"

struct BiNode
{
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
};

struct Info
{
	struct BiNode *node;
	bool flag;
};


struct Info * createInfo(struct Binode *node, bool flag)
{
	struct Info *info = malloc(sizeof(struct Info));
	info->node = node;
	info->flag = flag;

	return info;
}

//������ѹ��ջ��
void nonRecursion(struct BiNode *root)
{
	//��ʼ��ջ
	SeqStack stack = Init_SeqStack();
	//�ȰѸ��ڵ�ѹ��ջ��
	Push_SeqStack(stack, createInfo(root, false));

	while (Size_SeqStack(stack) > 0)
	{
		//���ջ��Ԫ��
		struct Info * info = (struct Info *)Top_SeqStack(stack);
		Pop_SeqStack(stack);

		if (info->flag)
		{
			printf("%c", info->node->ch);
			free(info);
			continue;
		}
		info->flag = true;
		Push_SeqStack(stack, info);

		if (info->node->rchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->rchild, false));
		}
		if (info->node->lchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->lchild, false));
		}



		Destroy_SeqStack(stack);

	}

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


	nonRecursion(&nodeA);

}



	int main()
	{

		test();

		system("pause");
		return EXIT_SUCCESS;
	}