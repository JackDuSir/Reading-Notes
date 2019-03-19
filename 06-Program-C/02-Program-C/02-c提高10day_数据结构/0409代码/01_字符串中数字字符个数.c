#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
��������:ͳ���ַ��������ָ���
��������:str��ָ����Ҫ�������ַ��������ַ�����
	pCount�������������ַ�����ͨ��pCount���м�Ӹ�ֵ��
��������ֵ: �ɹ�����0 ʧ�ܷ���-1
*/

int getCount(const char *str, int *pCount)
{
	//if (NULL == str || NULL == pCount)	// �жϴ����������Ч��
	//{
	//	return -1;
	//}
	assert(str != NULL && pCount != NULL);
	while (*str != '\0') {
		//0-9	48	57
		if ( *str >= '0' && *str <= '9') {	// �ж��ַ��Ƿ�Ϊ�����ַ�
			(*pCount)++;
		}
		str++;	// ָ�����
	}
	return 0;
}

void test()
{
	const char *str = "qwer121qwer32qwer2";
	int num = 0;
	if (getCount(str, &num) == 0) {
		printf("%s ���� %d ������!!!\n",str,num);
	}
}

int main(void)
{
	test();
	getchar();
	return 0;
}