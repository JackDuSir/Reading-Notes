#include"teachmanage.h"


struct Person
{
	struct site *next;
	unsigned int id;
	char name[64];
	unsigned int age;
	int array[3];
};

void prinn(void *d1)//打印函数
{

	struct Person *p1 = (struct Person*)d1;
	printf(" %d %s %d ",p1->id, p1->name, p1->age);

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", p1->array[i]);
	}
	printf("\n");
}

int comparee(void *d1, void*d2)//按值查找打印
{
	if (NULL == d1)
	{
		return 0;
	}
	if (NULL == d2)
	{
		return 0;
	}
	struct Person *p1 = (struct Person *)d1;
	struct Person *p2 = (struct Person *)d2;
	
	return p1->id == p2->id;
}

void test()
{
	struct teacher *mylink = NULL;
	init_data(&mylink);
	//结构体中包含数组，可以用这种方法赋值
	struct Person *p7 = malloc(sizeof(struct Person));
	
	 



	int i = 0;
	scanf("%d", &i);
	p7->id = i;

	struct Person p1 = { NULL, 2016001, "马  云", 18, { 80, 90, 70 } };
	struct Person p2 = { NULL, 2016002, "马化腾", 19, { 50, 30, 20 } };
	struct Person p3 = { NULL, 2016003, "李彦宏", 20, { 80, 90, 70 } };
	struct Person p4 = { NULL, 2016004, "任正非", 21, { 80, 90, 70 } };
	struct Person p5 = { NULL, 2016005, "张小虎", 23, { 100, 90, 70 } };

 


	insert_data(mylink, 1, &p1);
	insert_data(mylink, 2, &p2);
	insert_data(mylink, 3, &p3);
	insert_data(mylink, 4, &p4);
	findall_data(mylink, prinn);//遍历
	printf("----------------\n");
	delete_data(mylink, 3);
	findall_data(mylink, prinn);
	printf("你要查找的是\n");
	find_data(mylink, 3, prinn);
	printf("----------------\n");
	alter_data(mylink,0, &p5);
	findall_data(mylink, prinn);
	struct Person p6 = { NULL, 2016003, "李彦宏", 90, { 80, 90, 60 } };
	pricefine_data(mylink, &p6, comparee, prinn);
}

void main()
{

	test();
	system("pause");
}

