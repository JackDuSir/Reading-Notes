/*************************************************************************
	> File Name: test.c
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月22日 星期五 15时41分08秒
 ************************************************************************/

#include"QueueList.h"

typedef struct _Person
{
	QueueNode next;
	char name[64];
	int age;
} Person;



void test()
{
	QueueList queue = Init_LinkQueue();

	// 创建数据
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p4 = { NULL, "ddd", 40 };
	Person p5 = { NULL, "eee", 50 };

	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);

	Person *pTail = (Person *)Tail_LinkQueue(queue);
	printf("Tail data: [Name:%s Age:%d]\n", pTail->name, pTail->age);

	while(Size_LinkQueue(queue) > 0)
	{
		Person *person = (Person *)Head_LinkQueue(queue);
		printf("Name:%s Age:%d\n", person->name, person->age);
		Pop_LinkQueue(queue);
	}
	printf("Size:%d\n", Size_LinkQueue(queue));

	Destroy_LinkQueue(queue);
}

int main()
{
	test();

	return 0;
}
