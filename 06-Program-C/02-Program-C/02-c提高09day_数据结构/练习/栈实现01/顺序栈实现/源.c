#include"serlinklist.h"


struct Person
{
	char arr[64];
	int size;


};



void test()

{
	struct SStack  *pp = init_seqstak();
	struct Person p1 = { "aaaa", 100 };
	struct Person p2 = { "bbbb", 200 };
	struct Person p3 = { "cccc", 300 };
	struct Person p4 = { "dddd", 400 };
	struct Person p5 = { "eeee", 500 };

	push_seqstack(pp, &p1);
	push_seqstack(pp, &p2);
	push_seqstack(pp, &p3);
	push_seqstack(pp, &p4);
	push_seqstack(pp, &p5);

	while (size_seqstack(pp) > 0)
	{
		struct Person *myperson = (struct Person *)top(pp);
		printf("%s %d\n", myperson->arr, myperson->size);
		pop_seqstack(pp);
	}

}

void main()
{

	test();
	system("pause");


}