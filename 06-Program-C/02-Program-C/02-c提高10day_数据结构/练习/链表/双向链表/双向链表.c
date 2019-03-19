#include"twolinklist.h"

struct Person
{
	char name[64];
	int age;
};

void print(void *d1)
{
	struct Person *p1 = (struct Person*)d1;
	printf("%s %d\n", p1->name, p1->age);
}


void test()
{
	struct linklist *mylink = NULL;
	mylink = init();

	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "ccc", 20 };
	struct Person p3 = { "eee", 30 };
	struct Person p4 = { "fff", 40 };
	struct Person p5 = { "jjj", 50 };
	struct Person p6 = { "kkk", 60 };


	inser(mylink, 0, &p1);
	inser(mylink, 1, &p2);
	inser(mylink, 2, &p3);
	inser(mylink, 3, &p4);
	inser(mylink, 4, &p5);
	inser(mylink, 5, &p6);
	
	show(mylink, print);
	printf("----------\n");
	reverseshow(mylink, print);

	deletenode(mylink, 3);
	printf("----------\n");
	show(mylink, print);
	printf("-------------------\n");

	destroy(mylink);
	//reverseshow(mylink, print);
}

void main()
{

	test();
	system("pause");
}