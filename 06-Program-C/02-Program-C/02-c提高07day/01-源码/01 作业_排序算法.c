#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void SelectSort(void *ptr,int ele_size,int ele_num,int(*compare)(void*,void*))
{

	char *temp = malloc(ele_size);

	for (int i = 0; i < ele_num; ++i)
	{

		int minOrMax = i;
		
		
		for (int j = i + 1; j < ele_num; ++j)
		{
			char *pJ = (char *)ptr + j * ele_size;
			char *pMinOrMax = (char *)ptr + minOrMax * ele_size;
			if (compare(pJ, pMinOrMax))
			{
				minOrMax = j;
			}

		}


		if (minOrMax != i)
		{

			char *pMinOrMax = (char *)ptr + minOrMax * ele_size;
			char *pI = (char *)ptr + i * ele_size;

			//对下标为j和minormax的两个数进行交换
			memcpy(temp, pI, ele_size);
			memcpy(pI, pMinOrMax, ele_size);
			memcpy(pMinOrMax, temp, ele_size);

		}


	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;

	}
	

}

int compareInt(void *d1,void *d2)
{
	int *p1 = (int *)d1;
	int *p2 = (int *)d2;

	return *p1 > *p2;
}

void test01()
{
	int arr[] = { 7, 4, 9, 2, 1 };
	SelectSort(arr, sizeof(int), sizeof(arr) / sizeof(int), compareInt);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}