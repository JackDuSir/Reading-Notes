#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//str���ַ���ָ�룬pConut�����ָ���
int getCount(const char *str, int *pCount)
{
	if (NULL == str)
	{
		return -1;
	}

	const char *mystr = str;
	int i = 0;
	while (*mystr != '\0')
	{

		if ((*mystr >= '0') && (*mystr <= '9'))
		{
			++i;
		}
		*pCount = i;
		++mystr;
	}
	return 0;
}

int main()
{

	char arr[] = "abcdef0234569";
	int i = 0;
	int j = 0;
	j = getCount(arr, &i);
	printf("�ַ��������ָ���Ϊ:%d ��������ֵΪ: %d", i, j);

	system("pause");

}