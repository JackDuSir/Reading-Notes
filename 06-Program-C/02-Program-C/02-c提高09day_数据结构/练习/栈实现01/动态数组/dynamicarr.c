#include "dynamicarr.h"




//初始化化数组,用户输入一个数组的长度
void * initarr(int length)//初始化数组，开辟一个空间返回地址
{
	if (length == 0)
	{
		return NULL;
	}

	struct myarray *myarr = malloc(sizeof(struct myarray));

	if (NULL == myarr)
	{
		return NULL;
	}
	myarr->lenin = length;
	//给数组分配一定的长度
	myarr->arrhead = malloc(sizeof(void *)*myarr->lenin);
	myarr->size = 0;

	return myarr;
}
//插入数据
void insertarr(void *array,int pos, void *data)//插入数据
{
	if (NULL==array)
	{
		return;
	}

	if (pos < 0)
	{
		return;
	}
	if (NULL == data);

	struct myarray *myarr = (struct myarray *)array;

	if (pos > myarr->size)
	{
		pos = myarr->size;
	}

	if (myarr->size >= myarr->lenin)
	{
		int newlenin = myarr->lenin * 2;

		void **newarray = malloc(sizeof(void *) * newlenin);

		memset(newarray, 0, sizeof(void *) * newlenin);
		
		memcpy(newarray, myarr->arrhead, myarr->lenin);

		free(myarr->arrhead);

		myarr->arrhead = newarray;
		myarr->lenin = newlenin;

	}

	//i=-1;pos=0;
	for (int i = myarr->size -1; i >= pos; --i)
	{
		myarr->arrhead[i+1] = myarr->arrhead[i];
	}

	myarr->arrhead[pos] = data;
	myarr->size++;
}
//删除数据
void deletedata(void *array, int pos)//根据位置删除
{
	if (NULL == array)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;

	if (NULL == myarr)
	{
		return;
	}

	if (pos<0 || pos>myarr->size)
	{
		return;
	}

	for (int i = pos; i < myarr->size; ++i)
	{
		myarr->arrhead[i] = myarr->arrhead[i + 1];
	}

	myarr->size--;
}
//遍历数据
void show(void* array,void(*comprint)(void *))//显示数据
{
	if (array == NULL)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;
	for (int i = 0; i < myarr->size; ++i)
	{
		comprint(myarr->arrhead[i]);
	}

}
//查找数据
void seek(void *array, void* data,int(*compare)(void *,void *))//根据值查找数据
{
	if (NULL == array)
	{
		return;
	}
	if (NULL==data)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;
	for (int i = 0; i < myarr->size; ++i)
	{
		if (compare(myarr->arrhead[i], data))
		{
			printf("找到在%d位置\n", i);
			return;
		}

	}
	printf("未找到!\n");

}
//根据位置查找数据
void fine(void *array, int pos, void (*print)(void *d1))
{
	if (NULL == array)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;

	if (pos < 0 || pos>myarr->size)
	{
		printf("你输入的位置不正确！\n");
		return;
	}

	print(myarr->arrhead[pos]);
	
}
//销毁数组
void emptyarr(void *array)
{
	if (NULL == array)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;
	if (myarr->arrhead != NULL)
	{
		free(myarr->arrhead);
		myarr = NULL;
	}

}
