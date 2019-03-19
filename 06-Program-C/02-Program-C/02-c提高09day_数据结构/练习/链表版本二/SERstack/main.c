#include "serstack.h"


struct Person
{
	char name[64];
	int age;
};


void test01()
{
	SeqStack pp = NULL;
	pp = Init_SeqStack();

	struct Person p1 = { "aaa", 200 };
	struct Person p2 = { "aaa", 300 };
	struct Person p3 = { "aaa", 400 };
	struct Person p4 = { "aaa", 500 };
	struct Person p5 = { "aaa", 600 };
	struct Person p6 = { "aaa", 700 };

	Push_SeqStack(pp, &p1);
	Push_SeqStack(pp, &p2);
	Push_SeqStack(pp, &p3);
	Push_SeqStack(pp, &p4);
	Push_SeqStack(pp, &p5);
	Push_SeqStack(pp, &p6);
	
	

	while (Size_SeqStack(pp) > 0)
	{
		struct Person *pp2 = (struct Person *)Top_SeqStack(pp);
		printf("%s %d", pp2->name, pp2->age);
		Pop_SeqStack(pp);
	}
	
	

	

	
}

void main()
{

	test01();

	system("pause");

}