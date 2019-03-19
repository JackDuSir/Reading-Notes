#include"stack.h"



struct Perosn
{
	char arr[64];
	int size;
};

void test()
{

	SeqStack pp = Init_SeqStack();
	struct Perosn p1 = { "aaaa", 100 };
	struct Perosn p2 = { "bbbb", 200 };
	struct Perosn p3 = { "cccc", 300 };
	struct Perosn p4 = { "dddd", 400 };
	struct Perosn p5 = { "eeee", 500 };
	Push_SeqStack(pp, &p1);
	Push_SeqStack(pp, &p2);
	Push_SeqStack(pp, &p3);
	Push_SeqStack(pp, &p4);
	Push_SeqStack(pp, &p5);

	while (Size_SeqStack(pp) > 0)
	{
		struct Perosn *pp1 = (struct Perosn *)Top_SeqStack(pp);
		printf("%s %d\n", pp1->arr, pp1->size);
		Pop_SeqStack(pp);
	}
}



void main()
{
	test();
	system("pause");
}