#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void sport(void * arr, int elementsize, int length, int(*compare)(void *d1,void *d2))
{
	char *array = (char*)arr;
	char *temp = malloc(elementsize);
	for (int i = 0; i < length; ++i)
	{
		for (int j = i + 1; j < length; ++j)
		{
			char *p1 = (char *)array + i * elementsize;
			char *p2 = (char *)array + j * elementsize;
			if (compare)

			{
				memcpy(temp, p2,elementsize);
				memcpy(p2, p1,elementsize);
				memcpy(p1, temp,elementsize);
			}
		}
	}
}



int compare_y(void *d1, void *d2)
{
	int * p1 = (int *)d1;
	int * p2 = (int *)d2;

	return p1 < p2;

}



int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	sport(a, sizeof(int), sizeof(a) / sizeof(int), compare_y);

	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d  ", a[i]);
	}
	system("pause");

}