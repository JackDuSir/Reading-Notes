#define _CRT_SECURE_NO_WARNINGS
#include"bolinklist.h"

struct Person
{
	int age;
};


void print(void *nodedata)
{
	struct Person *data = (struct Person *)nodedata;
	printf("%d ", data->age);
}

void test()
{
	Link *link = NULL;
	link = InitLink();
	struct Person p1 = { 10 };
	struct Person p2 = { 20 };
	struct Person p3 = { 30 };
	struct Person p4 = { 40 };
	struct Person p5 = { 50 };
	struct Person p6 = { 666 };
	struct Person p7 = { 777 };
	struct Person p8 = { 30 };


	InsertNode(link, 0, &p1);
	InsertNode(link, 0, &p2);
	InsertNode(link, 0, &p3);
	InsertNode(link, 0, &p4);
	InsertNode(link, 0, &p5);
	InsertNode(link, 0, &p6);
	InsertNode(link, 3, &p7);
	printf("%d\n", link->size);
	show(link, print);
	PriceSeek(link, &p8);
	printf("-----------------------\n");

	DeleteNode(link, 3);

	//printf("%d\n", link->size);
	show(link, print);
	printf("-----------------------\n");
	//revshow(link, print);


	
	NodeAmount(link);
	deslinklist(link);
	
}






int main()
{

	test();

	system("pause");

}