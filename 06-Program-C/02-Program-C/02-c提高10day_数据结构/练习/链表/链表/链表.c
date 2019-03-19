#include"linklist.h"

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
	struct linklistinf *mylink = NULL;
	mylink = init();
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };

	inser(mylink, 0, &p1);
	inser(mylink, 0, &p2);
	inser(mylink, 0, &p3);
	inser(mylink, 0, &p4);

	show(mylink, print);
	destroy(mylink);
}

void main()
{
	test();

	system("pause");
}