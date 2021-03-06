#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Selection_Sort(
	void *array,
	size_t ElementSize,
	int ArrayLength,
	int(*compare)(void *eone, void *etwo))

{
	char *temp = malloc(ElementSize);

	for (int i = 0; i < ArrayLength; ++i)
	{
		int index = i;
		
		for (int j = i + 1; j < ArrayLength; ++j)
		{
			char *oneelement = (char *)array + index * ElementSize;

			char *twoelement = (char *)array + j * ElementSize;
			if (compare(oneelement, twoelement))
			{
				index = j;
			}

			if (index != i)

			{
				char *dataone = (char *)array + i * ElementSize;
				char *datatwo = (char *)array + index * ElementSize;

				memcpy(temp, dataone, ElementSize);
				memcpy(dataone, datatwo, ElementSize);
				memcpy(datatwo, temp, ElementSize);
			}
		}
	}

	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
}

int sort(void *d1, void *d2)
{
	int *p1 = (int *)d1;
	int *p2 = (int *)d2;

	return p1 < p2;
}



void test01()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		printf("%d  ", arr[i]);
	}

	printf("\n");

	Selection_Sort(arr, sizeof(int), sizeof(arr) / sizeof(int), sort);

	for (int i= 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		printf("%d  ", arr[i]);
	}
}


void main()
{
	test01();
	system("pause");
}



