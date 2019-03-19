#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILENAME1 "./student.txt"
#define FILENAME2 "./student2.txt"

typedef struct _tag_Student
{
	char name[24];
	int age;
}Student;

//����ڵ�
typedef struct _listNode
{
	//һ��ָ�����ѧ����Ϣ�Ľṹ��ָ��
	Student *stu;
	//һ��ָ�򱾽ṹ���ָ��
	struct _listNode *next;
}ListNode;

/*
��������:��studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
��������:studentInfo��ָ�����ѧ��name��age��һ���ַ�����
stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
��������ֵ: �ɹ�����0��ʧ�ܷ���-1��
*/

//���ַ��������ṹ���еĺ���
int  getStudentInfo(const char *studentInfo, Student *stu)

{
	//�жϴ����������Ч��
	if (NULL == studentInfo || NULL == stu)
	{
		return - 1;
	}
	//����һ��char��ָ�룬����ָ���
	const char *pbegin = NULL;
	//��������ָ�������ƶ�
	const char *pend = NULL;
	char buf[32] = { 0 };
	//�����ַ������õ�ѧ����Ϣname��age
	//name= haha age=23
	//�����ַ�����"="���ֵ�λ��
	//��ָ��pbginָ���ַ�����=λ��
	//strchar �������ҵ��ַ����ַ��״γ��ֵ�λ��
	pbegin = strchr(studentInfo, '=');
	pbegin++;//ȥ��=
	//ȥ���ո�
	while (*pbegin == ' ')
		pbegin++;
	pend = pbegin;
	//��һ������ָ�룬�����ӵ�ǰλ�ÿ�ʼ����ƶ�
	while (*pend !=' ')//�ҵ���һ���ո�֮ǰ
	{
		pend++;//
		strncpy(stu->name, pbegin, pend - pbegin);//�ҵ��ո�֮ǰ�����ҵ������ֵ�β��
		//Ȼ���õ�ǰָ���ȥ��ʼָ��õ�һ���������������Ⱦ������ֳ���
		//������������stu->name��
		//�ÿ�ʼ��ָ��ָ�����

		//��pbeginָ���pend��ʼ��һ�γ���=��λ��
		pbegin = strchr(pend, '=');
		//ȥ���ո�
		pbegin++;
		while (*pbegin == ' ')//ȥ���ո��ҵ���һ����Ϊ�ո���ַ�
		{
			pbegin++;
		}

		sscanf(*pbegin, "%d", &stu->age);

		return 0;		
	}
	
}

/*
��������:��ѧ������Ϣ��age�Ӵ�С��˳����뵽������
��������:
��������ֵ: �ɹ� 0 ,ʧ�� -1
*/

//
int insertNodeByAge(ListNode *head, Student *stu)
{
	//�жϴ���ṹ�����Ч��
	if (NULL == head)
	{
		return -1;
	}
	if (NULL == stu)
	{
		return -1;
	}

	ListNode *pCur = NULL;
	ListNode *pPre = NULL;
	ListNode *newNode = NULL;
	pPre = head;
	pCur = pPre->next;
	while (pCur!=NULL)
	{
		//�Ӵ�С����
		if (pCur->stu->age > stu->age)
		{
			//�ж�����ڵ�age��������age�Ĵ�С
			pPre = pCur;
			pCur = pCur->next;
		}
		else
		{
			break;//�ҵ��ȴ�����ڵ�ageС������ڵ�
			//������ڵ���Ҫ���뵽�ýڵ�ǰ
		}

	}
	//�½ڵ��������
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		return -1;
	}
	newNode->stu = stu;
	newNode->next = pCur;
	pPre->next = newNode;

	return 0;

}

/*
��������:����������ѧ������Ϣд���ļ���
��������:
��������ֵ:
*/

int writeToFile(ListNode *head, const char *filename)
{
	if (NULL == head || NULL == filename)
	{
		return -1;
	}
	FILE *fp = NULL;
	ListNode *pCur = NULL;

	fp = fopen(filename, "w");
	if (NULL == fp)
	{
		return -1;
	}
	pCur = head->next;
	while (pCur != NULL)
	{
		//�ѽṹ���е����ݸ�ʽ��д���ļ���
		fprintf(fp, "name=%s age=%d", pCur->stu->name, pCur->stu->age);
		pCur = pCur->next;
	}
	//д��֮��ر��ļ�
	fclose(fp);
	return 0;
}


/*
��������:��������,�ͷű�ռ�
��������:
��������ֵ:
*/
//������������ֻ��Ҫ������Ϣ�ṹ��
void destoryListNode(ListNode *head)
{
	if (NULL == head)
	{
		return;
	}
	ListNode *pCur = head;
	while (head!=NULL)
	{
	pCur = head->next;
	//

	if (head->stu != NULL)
		{
			free(head->stu);
			head->stu = NULL;
		}
		free(head);
		head = pCur;
	}
}
 





int main()
{



	system("pause");

}