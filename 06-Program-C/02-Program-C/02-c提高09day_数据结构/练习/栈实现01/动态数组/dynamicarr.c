#include "dynamicarr.h"




//��ʼ��������,�û�����һ������ĳ���
void * initarr(int length)//��ʼ�����飬����һ���ռ䷵�ص�ַ
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
	//���������һ���ĳ���
	myarr->arrhead = malloc(sizeof(void *)*myarr->lenin);
	myarr->size = 0;

	return myarr;
}
//��������
void insertarr(void *array,int pos, void *data)//��������
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
//ɾ������
void deletedata(void *array, int pos)//����λ��ɾ��
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
//��������
void show(void* array,void(*comprint)(void *))//��ʾ����
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
//��������
void seek(void *array, void* data,int(*compare)(void *,void *))//����ֵ��������
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
			printf("�ҵ���%dλ��\n", i);
			return;
		}

	}
	printf("δ�ҵ�!\n");

}
//����λ�ò�������
void fine(void *array, int pos, void (*print)(void *d1))
{
	if (NULL == array)
	{
		return;
	}
	struct myarray *myarr = (struct myarray *)array;

	if (pos < 0 || pos>myarr->size)
	{
		printf("�������λ�ò���ȷ��\n");
		return;
	}

	print(myarr->arrhead[pos]);
	
}
//��������
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
