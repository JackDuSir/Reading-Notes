#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME1 "./student.txt"
#define FILENAME2 "./student2.txt"

// ����ѧ����Ϣ�ṹ��
typedef struct _tag_Student {
	char name[24];
	int age;
}Student;

// ����ڵ�
typedef struct _listNode {
	Student *stu;
	struct _listNode *next;
}ListNode;

/*
��������:��studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
��������:studentInfo��ָ�����ѧ��name��age��һ���ַ�����
		  stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
��������ֵ: �ɹ�����0��ʧ�ܷ���-1��
*/
int getStudentInfo(const char *studentInfo, Student *stu)
{
	//�жϴ����������Ч��
	if (NULL == studentInfo || NULL == stu) {
		return -1;
	}

	const char *pbegin = NULL;
	const char *pend = NULL;
	char buf[32] = { 0 };

	// �����ַ���,�õ�ѧ����Ϣname �� age
	// name= haha  age=23
	// �����ַ�����"=" ���ֵ�λ��
	pbegin = strchr(studentInfo, '=');
	pbegin++;	//ȥ���ո�
	while (*pbegin == ' ')		//ȥ���ո�,�ҵ���һ����Ϊ�ո���ַ�
		pbegin++;
	pend = pbegin;
	while (*pend != ' ')			//��pbegin ��λ��������,�ҵ���һ��Ϊ�ո���ַ�
		pend++;
	strncpy(stu->name, pbegin, pend - pbegin);	// pend �� pbegin ֮����ַ�����name

	pbegin = strchr(pend, '=');
	pbegin++;	//ȥ���Ⱥ�
	while (*pbegin == ' ')		//ȥ���ո�,�ҵ���һ����Ϊ�ո���ַ�
		pbegin++;
	sscanf(pbegin, "%d", &stu->age);
	
	return 0;
}

/*
��������:��ѧ������Ϣ��age�Ӵ�С��˳����뵽������
��������:
��������ֵ: �ɹ� 0 ,ʧ�� -1
*/
int insertNodeByAge(ListNode * head, Student *stu)
{
	//�жϴ����������Ч��
	if (NULL == head || NULL == stu) {
		return -1;
	}

	ListNode * pCur = NULL;
	ListNode * pPre = NULL;
	ListNode * newNode = NULL;
	
	pPre = head;
	pCur = pPre->next;
	while (pCur != NULL) {
		if (pCur->stu->age > stu->age) {//�ж�����ڵ�����ݺʹ�����ڵ�����age�Ĵ�С
			pPre = pCur;	
			pCur = pCur->next;
		}
		else {
			break;	//�ҵ��ȴ�����ڵ�ageС������ڵ�,������ڵ�����뵽��ǰ�ڵ�ǰ
		}
	}

	//�½���������
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == newNode) {
		return  -1;
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
int writeToFile(ListNode * head, const char * filename)
{
	if (NULL == head || NULL == filename)
	{
		return -1;
	}
	FILE * fp = NULL;
	ListNode *pCur = NULL;

	fp = fopen(filename, "w");
	if (NULL == fp) {
		return -1;
	}
	pCur = head->next;
	while (pCur != NULL) {
		//��ʽ�����ļ���д������
		fprintf(fp, "name=%s age=%d\n", pCur->stu->name, pCur->stu->age);
		pCur= pCur->next;
	}
	fclose(fp);

	return 0;
}

/*
��������:��������,�ͷű�ռ�
��������:
��������ֵ: 
*/
void destoryListNode(ListNode * head)
{
	if (NULL == head) {
		return;
	}
	ListNode * pCur = head;
	while (head != NULL) {
		pCur = pCur->next;	// �����������һ���ڵ�����
		if (head->stu != NULL) {
			free(head->stu);
			head->stu = NULL;	//�ͷ�p->stu��ָ����ڴ�
		}
		free(head);
		head = pCur;
	}

}

void test()
{
	FILE *fp = NULL;
	ListNode * head = NULL; 
	char buf[BUFSIZ] = { 0 };

	// 1. ���ļ� student.txt
	fp = fopen(FILENAME1, "r");
	if (NULL == fp) {
		printf("�ļ���ʧ��\n");
		exit(1);
	}

	// ��������ͷ�ڵ�
	head = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == head) {
		printf("malloc error!!\n");
		exit(1);
	}
	// ͷ�ڵ㲻��������,��Ϊ����ָ��
	head->stu = NULL;
	head->next = NULL;

	// ��ȡ�ļ����ݵ�������
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		Student *stu = (Student *)malloc(sizeof(Student));
		memset(stu, 0, sizeof(Student));
		if (NULL == stu) {
			printf("malloc error\n");
			exit(1);
		}
		// ��ȡÿһ�е�ѧ����Ϣ,��������stu��ָ����ڴ�ռ���
		getStudentInfo(buf, stu);
		//3.��stu����������������
		insertNodeByAge(head, stu);
	}
	//5.�������еĽ����Ϣд��student2.txt��
	writeToFile(head, FILENAME2);
	//6.��������
	destoryListNode(head);
}

int main(void)
{
	test();
	return 0;
}