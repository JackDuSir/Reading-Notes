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

//��ӡ���ݣ���ӡ�������ݣ�������Ϣ�����д���λ��
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
		//�ж��Ƿ���������
		if (compare_01(p))
		{
			//����������ž���ջ
			Push_SeqStack(mystack, p);
		}

		if (compare_02(p))
		{
			//ջ��������ʱ˵����������
			if (Size_SeqStack(mystack) > 0)
			{
				//�������žͳ�ջ
				Pop_SeqStack(mystack);
			}
			else
			{
				print(arr, "û��ƥ���������", p);
			}
		}
		
		++p;
	}

	while (Size_SeqStack(mystack) != 0)
	{
		print(arr, "û��ƥ���������", Top_SeqStack(mystack));
		Pop_SeqStack(mystack);
	}

	Destroy_SeqStack(mystack);
}


void main()
{
	test();

	system("pause");
}