#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _tag_Student {
	char name[24];
	int age;
}Student;

typedef struct _listNode {
	Student *stu;
	struct _listNode *next;
}ListNode;


int getStudentInfo(char *studentInfo, Student *stu)

{
	Student * mytag = stu;
	FILE *file = fopen("student.txt", "r");
	if (NULL == file)
	{
		printf("文件打开失败\n");
	}

	char buf[1024] = { 0 };

	while (fgets(buf, 1024, file) != NULL)
	{
		char *temp = strtok(buf, "=");
		strcpy(mytag->name, temp);
		char *temp = strtok(NULL, "=");
		mytag->age = atoi(temp);
	}
}

void *init()
{

	ListNode *mylist = malloc(sizeof(ListNode));
	mylist->next = NULL;
	mylist->stu = NULL;

}


//链表函数
void insert(ListNode *mynode,void *data)
{
	if (NULL == mynode)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	ListNode *node = mynode;
	node->stu = (Student *)data;
	node->next = &(node);
}











int main()
{
	test01();
	system("pause");

}




int main()
{



	system("pause");

}