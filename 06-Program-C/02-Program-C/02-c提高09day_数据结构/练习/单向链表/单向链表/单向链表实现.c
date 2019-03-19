#include"seqlinklist.h"



struct Person
{
	char arr[64];
	int str;
};

void print(void *d1)
{
	struct Person *p1 = (struct Person *)d1;
	printf("%s %d\n", p1->arr, p1->str);

}



void test01()
{
	struct linklistmessage *mylink = init_link();

	struct Person p1 = { "aaa", 100 };
	struct Person p2 = { "bbb", 200 };
	struct Person p3 = { "ccc", 300 };
	struct Person p4 = { "ddd", 400 };
	struct Person p5 = { "eee", 500 };

	insert_link(mylink, 0, &p1);
	insert_link(mylink, 1, &p2);
	insert_link(mylink, 2, &p3);
	insert_link(mylink, 3, &p4);
	insert_link(mylink, 4, &p5);
	fineall_link(mylink, print);
	printf("-----------------\n");
	delete_link(mylink, 3);
	fineall_link(mylink, print);

	findnode_link(mylink, 3, print);
	printf("%d\n", link_node(mylink));
}

int main()
{
	test01();
	system("pause");

}