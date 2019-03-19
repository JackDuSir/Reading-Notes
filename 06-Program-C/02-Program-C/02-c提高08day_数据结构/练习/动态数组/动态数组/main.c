#include"DynamicArray.h"

struct Person
{
	char name[64];
	int age;
};

void myprint (void *d1)
{
	struct Person * p1 = (struct Person *)d1;
	printf("%s %d\n", p1->name, p1->age);


}

int compare(void *d1, void *d2)
{
	
	struct Person *p1 = (struct Person *)d1;
	struct Person *p2 = (struct Person *)d2;
	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;

}


void test01()
{
	struct DynamicArray *da = Init_DynamicArray(5);
	struct Person p1 = { "aaaaa", 100 };
	struct Person p2 = { "bbbbb", 200 };	
	struct Person p3 = { "ccccc", 300 };
	struct Person p4 = { "ddddd", 400 };
	struct Person p5 = { "eeeee", 500 };

	Insert_DynamicArray(da, 100, &p1);
	Insert_DynamicArray(da, 100, &p2);
	Insert_DynamicArray(da, 100, &p3);
	Insert_DynamicArray(da, 100, &p4);
	Insert_DynamicArray(da, 100, &p5);

	Foreach_DynamicArray(da, myprint);
}
void main()
{
	
	test01();
	system("pause");


}