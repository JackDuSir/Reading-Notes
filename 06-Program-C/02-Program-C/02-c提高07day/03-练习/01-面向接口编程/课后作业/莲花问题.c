#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lotus(int i)
{
	if (i == 1)
	{
		return 1;
	}

	else
	{
		return lotus(i - 1) * 2;
	}
}


int main()
{

	int i = 0,j=0;
	i = lotus(30);
	j = lotus(23);
	float trade = 0.0;
	trade = (float)j / (float)i;
	printf("第30天莲花的数量为%d\n", i);
	printf("第23天莲花的数量为%d\n", j);
	printf("第23天莲花占水池的j/i=%f\n",trade);
	system("pause");
}