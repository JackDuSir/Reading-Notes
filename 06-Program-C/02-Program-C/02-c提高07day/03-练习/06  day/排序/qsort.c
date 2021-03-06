#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//第一个参数是数组名，第二个参数为数组长度，第三是每个元素所占字节
void qsort(void *arr,int len,size_t size,int (*compare)(void *d1,void* d2))
{
	//给temp开辟size字节个大小，以char类型存储
	char * temp = malloc(size);
	for (int i = 0; i < len; ++i)
	{
		//记录下标、选择排序
		int minormax = i;
		for (int j = i + 1; j < size; ++j)
		{	//把从arr开始的j*size个字节以char*赋给pJ
			char *pJ = (char *) arr + j * size;
			char *pminmormax = (char *)arr + minormax * size;
			if (compare(pJ, pminmormax))
			{
				minormax = j;
			}
		}

		if (minormax != i)
		{
			char *pMinOrMax = (char *)arr + minormax;
			char *pI = (char *)arr + i*size;
			memcpy(temp, pI, size);
			memcpy(pI, pMinOrMax, size);
			memcpy(pMinOrMax, temp, size);
		}
	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}

}

int compareInt(void *d1, void *d2)
{
	int *p1 = (int *)d1;
	int *p2 = (int *)d2;
	return *p1 > *p2;
}




int main()
{



	system("pause");

}