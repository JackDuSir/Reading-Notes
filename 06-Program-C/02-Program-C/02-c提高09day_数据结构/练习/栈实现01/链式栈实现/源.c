#include"linklist.h"


struct Person
{
	struct structure *next;
	char arr[64];
	int size;
};

void test()
{
	struct Stru * mylinklist = NULL;
	mylinklist = init();
	struct Person p1 = { NULL, "aaaa", 100 };
	struct Person p2 = { NULL, "bbbb", 200 };
	struct Person p3 = { NULL, "cccc", 300 };
	struct Person p4 = { NULL, "dddd", 400 };
	struct Person p5 = { NULL, "eeee", 500 };

	push(mylinklist, &p1);
	push(mylinklist, &p2);
	push(mylinklist, &p3);
	push(mylinklist, &p4);
	push(mylinklist, &p5);
	

	printf("%d", statcksize(mylinklist));

	

	while (statcksize(mylinklist)>0)
	{ 

		struct Person * onenode = (struct Person *)top(mylinklist);

		printf("%s %d\n", onenode->arr, onenode->size);
		pop(mylinklist);
	}


}

void main()
{
	test();
	system("pause");

}
