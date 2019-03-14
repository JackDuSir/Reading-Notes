/*************************************************************************
	> File Name: char_reversal.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月14日 星期四 19时23分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void reverse_string(char* str)
{
	if (str == NULL)
		return;

	int begin = 0;
	int end = strlen(str) - 1;

	while(begin < end)
	{
		char temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;

		begin++;
		end--;
	}
}

void test()
{
	char str[] = "abcdefghj";
	printf("str = (%s)\n", str);
	reverse_string(str);
	printf("str = (%s)\n", str);
}

int main()
{
	test();
	return 0;
}
