#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct linknod
{
	struct linknod * next;
};

struct Linklinst
{
	//直接就分配结构大小内存，如果加上*就是分配四个字节
	struct linknod header;
	char name[64];
	int size;

};

void * initlink()//初始化链表
{
	struct Linklinst *myLiklinst = malloc(sizeof(struct Linklinst));
	if (NULL == myLiklinst)
	{
		return NULL;
	}

	myLiklinst->header.next = NULL;
	myLiklinst->size = 0;
	return myLiklinst;

}

void insert(struct Linklinst *inlink, int pos, void *data)//插入
{

	if (NULL == inlink)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct Linklinst *myinlink = (struct Linklinst *)inlink;

	struct linknod *mynode = &(myinlink->header);

	struct linknod *mydata = (struct linknod *)data;

	if (pos < 0 || pos > myinlink->size)
	{
		pos = myinlink->size;
	}

	struct linknod * pCuuer = mynode;
	
	for (int i = 0; i < pos; ++i)
	{
		pCuuer = pCuuer->next;
	}
	mydata->next = pCuuer->next;
	pCuuer->next = mydata;
	myinlink->size++;
}

void print(void * inlink, void(*pcom)(void *))//遍历
{
	if (NULL == inlink)
	{
		return;
	}

	struct Linklinst *myinlink = (struct Linklinst *)inlink;

	struct linknod *mylinknod = myinlink->header.next;

	while (mylinknod != NULL)
	{
		pcom(mylinknod);
		mylinknod = mylinknod->next;
	}

}





struct Person
{
	//这里
	struct linknod next;
	char arr[64];
	int size;
};


void pprint(void *a1)
{
	if (NULL == a1)
	{
		return;
	}
	struct Person *p1 = (struct Person *)a1;

	printf("%s %d\n", p1->arr, p1->size);
}

void delete(void *inlink, int pos)//根据位置删除
{
	if (NULL == inlink)
	{
		return;
	}
	struct Linklinst *myinlink = (struct Linklinst *)inlink;
	if (pos < 0 || pos>myinlink->size)
	{
		return;
	}

	struct linknod * mynode = &(myinlink->header);
	struct linknod * pCuure = NULL;
	for (int i = 0; i < pos; ++i)
	{
		pCuure = mynode;
		mynode = mynode->next;
	}
}




void texe01()
{
	struct Linklinst  *myLinklinst = NULL;

	struct Person  p1 = { NULL, "aaaa", 100 };
	struct Person  p2 = { NULL, "bbbb", 200 };
	struct Person  p3 = { NULL, "cccc", 300 };
	struct Person  p4 = { NULL, "dddd", 400 };
	struct Person  p5 = { NULL, "eeee", 500 };

	myLinklinst = initlink();
	insert(myLinklinst, 0, &p1);
	insert(myLinklinst, 0, &p2);
	insert(myLinklinst, 0, &p3);
	insert(myLinklinst, 0, &p4);
	insert(myLinklinst, 0, &p5);

	print(myLinklinst, pprint);

}




int main()
{

	texe01();

	system("pause");

}