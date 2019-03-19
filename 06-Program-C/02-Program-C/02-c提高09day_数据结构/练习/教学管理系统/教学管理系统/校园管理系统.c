#include"teachmanage.h"


struct Person
{
	struct site *next;
	unsigned int id;
	char name[64];
	unsigned int age;
	int array[3];
};

void prinn(void *d1)//��ӡ����
{

	struct Person *p1 = (struct Person*)d1;
	printf(" %d %s %d ",p1->id, p1->name, p1->age);

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", p1->array[i]);
	}
	printf("\n");
}

int comparee(void *d1, void*d2)//��ֵ���Ҵ�ӡ
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
	//�ṹ���а������飬���������ַ�����ֵ
	struct Person *p7 = malloc(sizeof(struct Person));
	
	 



	int i = 0;
	scanf("%d", &i);
	p7->id = i;

	struct Person p1 = { NULL, 2016001, "��  ��", 18, { 80, 90, 70 } };
	struct Person p2 = { NULL, 2016002, "����", 19, { 50, 30, 20 } };
	struct Person p3 = { NULL, 2016003, "�����", 20, { 80, 90, 70 } };
	struct Person p4 = { NULL, 2016004, "������", 21, { 80, 90, 70 } };
	struct Person p5 = { NULL, 2016005, "��С��", 23, { 100, 90, 70 } };

 


	insert_data(mylink, 1, &p1);
	insert_data(mylink, 2, &p2);
	insert_data(mylink, 3, &p3);
	insert_data(mylink, 4, &p4);
	findall_data(mylink, prinn);//����
	printf("----------------\n");
	delete_data(mylink, 3);
	findall_data(mylink, prinn);
	printf("��Ҫ���ҵ���\n");
	find_data(mylink, 3, prinn);
	printf("----------------\n");
	alter_data(mylink,0, &p5);
	findall_data(mylink, prinn);
	struct Person p6 = { NULL, 2016003, "�����", 90, { 80, 90, 60 } };
	pricefine_data(mylink, &p6, comparee, prinn);
}

void main()
{

	test();
	system("pause");
}

