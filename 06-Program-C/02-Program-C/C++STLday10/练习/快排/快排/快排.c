#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Person
{
	char name[20];
	int age;
};

typedef struct Person Person;





void binarysearch(void *data, int len,int da)
{
	if (data == NULL)
	{
		printf("传入的数据为空！\n");
		return;
	}
	Person **mydata = (Person **)data;
	int pre = mydata[0]->age;
	int wei = mydata[len-1]->age;
	int i = 0;
	while (pre >= wei)
	{
		printf("pre=%d,wei=%d\n", pre, wei);
		++i;
		int zhong = (pre + wei)/2;
		if (da == zhong)
		{
			printf("找到\n");
			break;
		}
		else if (da < zhong)
		{
			pre = zhong + 1;
		}
		else
		{
			wei = zhong - 1 ;
		}
	}
	printf("查找了%d次；", i);
}





void test()
{
	struct Person * parr[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		Person * p1 = malloc(sizeof(Person));
		sprintf(p1->name, "name_%c", 'a' + i);
		p1->age = i ;
		parr[i] = p1;
	}

	for (int i = 0; i < 10; ++i)
	{
		int max = i;
		for (int j = i + 1; j < 10; ++j)
		{
			if (parr[i]->age < parr[j]->age)
				max = j;
		}
		if (max != i)
		{
			Person * temp = parr[i];
			parr[i] = parr[max];
			parr[max] = temp;
		}
	}

	//selectsort(parr, 10);
	//selectsort(parr, 10);
	binarysearch(parr, 10, 4);

	for (int i = 0; i < 10; i++)
	{
		printf("%d %s\n", parr[i]->age, parr[i]->name);
	}
}





int main()
{

	test();
	system("pause");

}