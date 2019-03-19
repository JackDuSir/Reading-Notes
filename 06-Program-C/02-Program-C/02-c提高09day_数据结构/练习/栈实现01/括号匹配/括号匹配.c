#include "stack.h"

int IsLeft(char ch)//判断是否是（
{
	return (ch == '(');

}
int IsRight(char ch)
{
	return (ch == ')');
}

void printError(const char *str, char *errMsg, char *pos)
{
	
	printf("%s\n",str);
	
	for (int i = 0; i < pos - str; ++i)
	{
		printf(" ");
	}

	printf("A");
	printf("%s\n", errMsg);

}


void test()
{
	//首先初始化一个结构体
	struct SStack *pp = Init_SeqStack();
	char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = (char *)str;
	while (*p != '\0')
	{
		//如果*p是（括号就把p压栈
		if (IsLeft(*p))
		{
			Push_SeqStack(pp, p);
		}
		//如果是）括号就出栈
		if (IsRight(*p))
		{
			//判断栈是否为空
			if (Size_SeqStack(pp) > 0)
			{
				Pop_SeqStack(pp);
			}

			else
			{
				printError(str, "右括号没有匹配", p);
			}
		}
		p++;
	}

	//如果栈中不为空，就说明由左括号没有匹配
	while (pp->size != 0)
	{
		printError(str, "没有匹配的左括号", Top_SeqStack(pp));
		Pop_SeqStack(pp);
	}

}



void main()
{

	test();
	system("pause");

}