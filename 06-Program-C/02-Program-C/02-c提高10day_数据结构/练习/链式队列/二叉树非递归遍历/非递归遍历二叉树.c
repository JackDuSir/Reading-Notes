#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SeqStack.h"

struct BiNode
{
	char ch;
	//右子树
	struct BiNode *lchild;
	//左子树
	struct BiNode *rchild;
};

struct Info
{
	struct BiNode *node;
	bool flag;
};
//初始化化节点信息,构建函数
//复合语句
struct Info * createInfo(struct BiNode *node,bool flag)
{
	//给结构体开辟内存
	struct Info *info = malloc(sizeof(struct Info));
	//给结构体体成员赋值
	info->flag = flag;
	//把链表信息指向用户传入的
	info->node = node;
	return info;
}
//非递归遍历二叉树
void nonRecursion(struct BiNode *root)
{
	//初始化栈,定义一个无类型的指针让它指向结构体
	SeqStack stack = Init_SeqStack();
	//把根节点压入栈中

	Push_SeqStack(stack, createInfo(root, false));

	//判断栈是否为空
	while (Size_SeqStack(stack) > 0)
	{
		//获得栈顶元素
		struct Info *info = (struct Info *)Top_SeqStack(stack);
		//弹出栈顶元素
		Pop_SeqStack(stack);
		//如果为真就打印
		if (info->flag)
		{
			printf("%c ", info->node->ch);
			free(info);
			continue;
		}

		//将根节点压入栈中
		info->flag = true;
		Push_SeqStack(stack, info);

		//将右子树压入栈中
		if (info->node->rchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->rchild,false));
		}
		//将左子树压入栈中

		if (info->node->lchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->lchild,false));
		}

	}
	Destroy_SeqStack(stack);

		
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

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}