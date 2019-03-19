#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
函数功能:统计字符串中数字个数
函数参数:str：指向所要求数字字符个数的字符串；
	pCount：将所求数字字符个数通过pCount进行间接赋值。
函数返回值: 成功返回0 失败返回-1
*/

int getCount(const char *str, int *pCount)
{
	//if (NULL == str || NULL == pCount)	// 判断传入参数的有效性
	//{
	//	return -1;
	//}
	assert(str != NULL && pCount != NULL);
	while (*str != '\0') {
		//0-9	48	57
		if ( *str >= '0' && *str <= '9') {	// 判断字符是否为数字字符
			(*pCount)++;
		}
		str++;	// 指针后移
	}
	return 0;
}

void test()
{
	const char *str = "qwer121qwer32qwer2";
	int num = 0;
	if (getCount(str, &num) == 0) {
		printf("%s 中有 %d 个数字!!!\n",str,num);
	}
}

int main(void)
{
	test();
	getchar();
	return 0;
}