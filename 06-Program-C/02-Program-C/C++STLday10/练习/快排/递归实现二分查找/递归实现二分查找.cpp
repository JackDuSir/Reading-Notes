#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 1024



void BinarySearch(int pre,int pcu,int *arr, int len,int data,int i)
{
	if (NULL == arr)
	{
		printf("传的数据为空！\n");
		return;
	}
	
	int cen = (pre + pcu) / 2;
	printf("第%d次 ", i);
	printf("pre=%d cen=%d pcu=%d\n", pre,cen,pcu);
	
	if (pre <= pcu)
	{
		i++;
		if (data > arr[cen])
		{
			pre = cen + 1;
			BinarySearch(pre, pcu, arr, len, data, i);
		}
		else if (data < arr[cen])
		{
			pcu = cen - 1;
			BinarySearch(pre, pcu, arr,len,data,i);
		}
		else 
		{
			printf("找到!\n");
			printf("你查找的数据为:%d\n", arr[cen]);
			printf("查找次数为%d\n", i);
			return;	
		}
	}
	else
	{
		printf("查找%d次未找到！\n",i);
	}
}




void selectsort(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int max = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[max])
			{
				max = j;
			}
		}
		if (max != i)
		{
			int temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}


void printarr(int *arr, int len)
{
	for (int i = 0; i < len ; ++i)
	{
		if ((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%5d", arr[i]);
	}
	printf("\n");
}


void test()
{
	time_t ts;
	unsigned int data = (unsigned int)time(&ts);
	srand(data);
	int arr[N] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		arr[i] = rand()% 1024 +1;
	}
	printf("\n-----------------排序前---------------------\n");
	printarr(arr, N);
	selectsort(arr, N);
	printf("\n-----------------排序后---------------------\n");
	printarr(arr, N);
	int pre = arr[0];
	int pcu = arr[N-1];
	int i = 0;
	int a = 0;
	printf("请输入你要查找的数据\n");
	scanf("%d", &a);
	BinarySearch(pre, pcu, arr, N, a, i);

}

	




int main()
{

	test();

	system("pause");

}