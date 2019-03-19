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
��������:��studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
��������:studentInfo��ָ�����ѧ��name��age��һ���ַ�����
stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
��������ֵ: �ɹ�����0��ʧ�ܷ���-1��
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
��������:��ѧ������Ϣ��age�Ӵ�С��˳����뵽������
��������:
��������ֵ: �ɹ� 0 ,ʧ�� -1
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
��������:����������ѧ������Ϣд���ļ���
��������:
��������ֵ:
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
��������:��������,�ͷű�ռ�
��������:
��������ֵ:
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