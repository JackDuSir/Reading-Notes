#include "LinkLins.h"

struct Person
{
	char arr[20];
	int size;
};


void print(void *d1)
{
	struct Person *p1 = (struct Person *)d1;
	printf("%s %d\n", p1->arr, p1->size);
}



void test01()
{
	struct Person *pp = NULL;
	struct Person p1 = { "aaaa", 100 };
	struct Person p2 = { "bbbb", 200 };
	struct Person p3 = { "cccc", 300 };
	struct Person p4 = { "dddd", 400 };
	struct Person p5 = { "eeee", 500 };
	struct Person p6 = { "ffff", 600 };

	struct message *mymessage = NULL;
	mymessage = initlinklins();
	insertnode(mymessage, 0, &p1);
	insertnode(mymessage, 1, &p2);
	insertnode(mymessage, 2, &p3);
	insertnode(mymessage, 3, &p4);
	insertnode(mymessage, 4, &p5);
	stamp(mymessage, print);
	deletenode(mymessage, 2);
	stamp(mymessage, print);
	printf("%d",nodenumber(mymessage));
}

void main()
{
	test01();
	system("pause");
}