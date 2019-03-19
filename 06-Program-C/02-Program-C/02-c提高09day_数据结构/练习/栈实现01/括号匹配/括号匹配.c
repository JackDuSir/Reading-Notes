#include "stack.h"

int IsLeft(char ch)//�ж��Ƿ��ǣ�
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
	//���ȳ�ʼ��һ���ṹ��
	struct SStack *pp = Init_SeqStack();
	char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = (char *)str;
	while (*p != '\0')
	{
		//���*p�ǣ����žͰ�pѹջ
		if (IsLeft(*p))
		{
			Push_SeqStack(pp, p);
		}
		//����ǣ����žͳ�ջ
		if (IsRight(*p))
		{
			//�ж�ջ�Ƿ�Ϊ��
			if (Size_SeqStack(pp) > 0)
			{
				Pop_SeqStack(pp);
			}

			else
			{
				printError(str, "������û��ƥ��", p);
			}
		}
		p++;
	}

	//���ջ�в�Ϊ�գ���˵����������û��ƥ��
	while (pp->size != 0)
	{
		printError(str, "û��ƥ���������", Top_SeqStack(pp));
		Pop_SeqStack(pp);
	}

}



void main()
{

	test();
	system("pause");

}