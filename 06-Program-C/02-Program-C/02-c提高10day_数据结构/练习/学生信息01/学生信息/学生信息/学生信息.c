#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#define FILENAME1 "./student.txt"
#define FILENAME2 "./student2.txt"


typedef struct _tag_Student
{
	char name[64];
	int age;

}Student;

typedef struct _linkNode
{
	Student* node;
	struct _linkNode *Next;
}ListNode;


/*
函数功能:从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。
函数参数:studentInfo：指向包含学生name和age的一个字符串。
stu：指向用于保存学生信息的结构体。
函数返回值: 成功返回0，失败返回-1。
*/
int  getStudentInfo(char *studentInfo, Student * stu)
{

	if (NULL == studentInfo)
	{
		return -1;
	}
	if (NULL == stu)
	{
		return -1;
	}
	const char buf[BUFSIZ] = { 0 };

	const char *pCurr = NULL;
	const char *pre = NULL;

	pre = strchr(studentInfo, '=');
	pre++;

	while( *pre == ' ')
	{
		pre++;
	}

	pCurr = pre;

	while ( *pCurr != ' ')
	{
		pCurr++;
	}

	strncpy(stu->name, pre, pCurr - pre);

	pre = strchr(pCurr, '=');
	pre++;

	while ( *pre == ' ')
	{
		pre++;
	}

	sscanf(pre, "%d", &stu->age);

	return 0;
}

/*
函数功能:将学生的信息按age从大到小的顺序插入到链表中
函数参数:
函数返回值: 成功 0 ,失败 -1
*/


int insertNodeByAge(ListNode * head, Student *stu)
{
	
	if (NULL == head)
	{
		return -1;
	}
	if (NULL == stu)
	{
		return -1;
	}

	ListNode * pre = head;
	ListNode *pCurr = head->Next;

	while (pCurr != NULL)
	{
		if (pCurr->node->age > stu->age)
		{
			pre = pCurr;
			pCurr = pCurr->Next;
		}
		else
		{
			break;
		}	
	}

	ListNode * newnode = malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		return -1;
	}

	newnode->node = stu;
	newnode->Next = NULL;

	newnode->Next = pCurr;
	pre->Next = newnode;
	return 0;
}

/*
函数功能:将链表结点中学生的信息写入文件中
函数参数:
函数返回值:
*/
int writeToFile(ListNode * head, const char * filename)
{
	if (NULL == head)
	{
		return -1;
	}
	if (NULL == filename)
	{
		return -1;
	}

	ListNode *pCurr = head->Next;
	FILE *file = fopen(filename, "w");
	while (pCurr != NULL)
	{
		fprintf(file, "name=%s age=%d\r\n", pCurr->node->name, pCurr->node->age);
		
		pCurr = pCurr->Next;
	}
	fclose(file);
	return 0;

}

/*
函数功能:销毁链表,释放表空间
函数参数:
函数返回值:
*/
void destoryListNode(ListNode * head)
{
	if (NULL == head)
	{
		return;
	}

	ListNode *pCurr = head;

	while (head!= NULL)
	{
		pCurr = head->Next;
		if (head->node != NULL)
		{
			free(head->node);
			head->node = NULL;
		}
		free(head);
		head = NULL;
		head = pCurr;
	}	
}





void test()
{

	FILE *fp = NULL;
	char buf[BUFSIZ] = { 0 };
	ListNode *Node = NULL;

	fp = fopen(FILENAME1, "r");
	ListNode *head = malloc(sizeof(ListNode));
	head->Next = NULL;
	head->node = NULL;
	if (NULL == head)
	{
		return;
	}

	while (fgets(buf,BUFSIZ,fp)!=0)
	{
		Student *stu = malloc(sizeof(Student));
		if (NULL == stu)
		{
			exit(1);
		}

		memset(stu, 0, sizeof(Student));
		getStudentInfo(buf, stu);
		insertNodeByAge(head, stu);
	}

	fclose(fp);
	writeToFile(head, FILENAME2);
	destoryListNode(head);
}

int main()
{
	test();
	system("pause");
}