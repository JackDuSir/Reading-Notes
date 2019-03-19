#include "stack.h"


int compare_01(void *p)
{
	char *d = (char *)p;
	return *d == '(';
}

int compare_02(void *p)
{

	char *d = (char *)p;
	return *d == ')';

}

//打印数据，打印数据内容，错误信息，还有错误位置
void print(char *arr, char *err, char * pos)
{
	printf("%s\n", arr);
	for (int i = 0; i < pos - arr; ++i)
	{
		printf(" ");
	}
	printf("A  ");
	printf("%s\n", err);

}


void test()
{
	char arr[] = "5 + 5 * (6( + 9 / 3 * 1) - (1) + 3(";
	char *p = arr;

	struct SStack *mystack = NULL;
	mystack = Init_SeqStack();
	while (*p != '\0')
	{
		//判断是否是左括号
		if (compare_01(p))
		{
			//如果是左括号就入栈
			Push_SeqStack(mystack, p);
		}

		if (compare_02(p))
		{
			//栈中有数据时说明有左括号
			if (Size_SeqStack(mystack) > 0)
			{
				//有左括号就出栈
				Pop_SeqStack(mystack);
			}
			else
			{
				print(arr, "没有匹配的右括号", p);
			}
		}
		
		++p;
	}

	while (Size_SeqStack(mystack) != 0)
	{
		print(arr, "没有匹配的左括号", Top_SeqStack(mystack));
		Pop_SeqStack(mystack);
	}

	Destroy_SeqStack(mystack);
}


void main()
{
	test();

	system("pause");
}