#include"dynamicarr.h"

struct Person
{
	char arr[64];
	int age;
};


void print(void *d1)
{
	struct Person*p1 = (struct Person*)d1;
	printf("%s %d\n", p1->arr, p1->age);
}

int compaer(void *d1, void *d2)
{
	struct Person *p1 = (struct Person *)d1;
	struct Person *p2 = (struct Person *)d2;

	return strchr(p1->arr, p2->age) == 0 && p1->age == p2->age;
}

void pprint(void *d1)
{
	struct Person *p1 = (struct Person *)d1;
	printf("%s %d", p1->arr, p1->age);
}



void test()
{
	struct myarray *myArray = initarr(6);
	printf("%d\n", myArray->size);

	struct Person p1 = { "aaa", 100 };
	struct Person p2 = { "bbb", 200 };
	struct Person p3 = { "ccc", 300 };
	struct Person p4 = { "ddd", 400 };
	struct Person p5 = { "eee", 500 };
	struct Person p6 = { "fff", 600 };


	insertarr(myArray, 0, &p1);
	//printf("%d\n", myArray->size);

	insertarr(myArray, 1, &p2);
	//printf("%d\n", myArray->size);

	insertarr(myArray, 2, &p3);
	//printf("%d\n", myArray->size);

	insertarr(myArray, 3, &p4);
	//printf("%d\n", myArray->size);

	insertarr(myArray, 4, &p5);
	//printf("%d\n", myArray->size);

	insertarr(myArray, 5, &p6);
	//printf("%d\n", myArray->size);

	show(myArray, print);
	printf("----------------\n");
	deletedata(myArray, 3);

	struct Person p7 = { "ddd", 400 };
	seek(myArray, &p7, compaer);
	show(myArray, print);

	fine(myArray, 3, pprint);
	emptyarr(myArray);
}

void main()
{

	test();
	system("pause");

}