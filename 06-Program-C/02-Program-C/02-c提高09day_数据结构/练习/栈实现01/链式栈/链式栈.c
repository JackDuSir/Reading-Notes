#include"chainlink.h"


struct Person
{
	struct pheadnode next;
	char arr[64];
	int size;
};


void test()
{
	struct trust *pp = init();
	struct Person p1 = { NULL,"aaaa", 100 };
	struct Person p2 = { NULL,"bbbb", 200 };
	struct Person p3 = { NULL,"cccc", 300 };
	struct Person p4 = { NULL,"dddd", 400 };
	struct Person p5 = { NULL,"eeee", 500 };

	push(pp, &p1);
	push(pp, &p2);
	push(pp, &p3);
	push(pp, &p4);
	push(pp, &p5);
	//struct Person *pp1 = (struct Person *)pp->next.pnext;
	//struct Person *pp1 = (struct Person *)top(pp);
	//printf("%d", pp->size);
	printf("%d\n", node(pp));
	while (pp->size > 0)
	{

		struct Person *pp1 = (struct Person *)pp->next.pnext;
		//struct Person *pp1 = (struct Person *)top(pp);
		//printf("%d", pp->size);
		printf("%s %d\n", pp1->arr,pp1->size);
		

		//struct Person *pp2 = (struct Person *)top(pp);
		//printf("%s %d\n", pp2->arr, pp2->size);
		pop(pp);
	}
	
	dest(pp);
	
	


}

void main()
{

	test();
	system("pause");

}