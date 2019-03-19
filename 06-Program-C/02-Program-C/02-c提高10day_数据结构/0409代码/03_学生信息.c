#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME1 "./student.txt"
#define FILENAME2 "./student2.txt"

// 定义学生信息结构体
typedef struct _tag_Student {
	char name[24];
	int age;
}Student;

// 链表节点
typedef struct _listNode {
	Student *stu;
	struct _listNode *next;
}ListNode;

/*
函数功能:从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。
函数参数:studentInfo：指向包含学生name和age的一个字符串。
		  stu：指向用于保存学生信息的结构体。
函数返回值: 成功返回0，失败返回-1。
*/
int getStudentInfo(const char *studentInfo, Student *stu)
{
	//判断传入参数的有效性
	if (NULL == studentInfo || NULL == stu) {
		return -1;
	}

	const char *pbegin = NULL;
	const char *pend = NULL;
	char buf[32] = { 0 };

	// 处理字符串,得到学生信息name 和 age
	// name= haha  age=23
	// 查找字符串中"=" 出现的位置
	pbegin = strchr(studentInfo, '=');
	pbegin++;	//去除空格
	while (*pbegin == ' ')		//去除空格,找到第一个不为空格的字符
		pbegin++;
	pend = pbegin;
	while (*pend != ' ')			//从pbegin 的位置向后遍历,找到第一个为空格的字符
		pend++;
	strncpy(stu->name, pbegin, pend - pbegin);	// pend 和 pbegin 之间的字符就是name

	pbegin = strchr(pend, '=');
	pbegin++;	//去除等号
	while (*pbegin == ' ')		//去除空格,找到第一个不为空格的字符
		pbegin++;
	sscanf(pbegin, "%d", &stu->age);
	
	return 0;
}

/*
函数功能:将学生的信息按age从大到小的顺序插入到链表中
函数参数:
函数返回值: 成功 0 ,失败 -1
*/
int insertNodeByAge(ListNode * head, Student *stu)
{
	//判断传入参数的有效性
	if (NULL == head || NULL == stu) {
		return -1;
	}

	ListNode * pCur = NULL;
	ListNode * pPre = NULL;
	ListNode * newNode = NULL;
	
	pPre = head;
	pCur = pPre->next;
	while (pCur != NULL) {
		if (pCur->stu->age > stu->age) {//判断链表节点的数据和待插入节点数据age的大小
			pPre = pCur;	
			pCur = pCur->next;
		}
		else {
			break;	//找到比待插入节点age小的链表节点,待插入节点需插入到当前节点前
		}
	}

	//新结点插入链表
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
函数功能:将链表结点中学生的信息写入文件中
函数参数:
函数返回值: 
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
		//格式化向文件中写入内容
		fprintf(fp, "name=%s age=%d\n", pCur->stu->name, pCur->stu->age);
		pCur= pCur->next;
	}
	fclose(fp);

	return 0;
}

/*
函数功能:销毁链表,释放表空间
函数参数:
函数返回值: 
*/
void destoryListNode(ListNode * head)
{
	if (NULL == head) {
		return;
	}
	ListNode * pCur = head;
	while (head != NULL) {
		pCur = pCur->next;	// 保存链表的下一个节点数据
		if (head->stu != NULL) {
			free(head->stu);
			head->stu = NULL;	//释放p->stu所指向的内存
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

	// 1. 打开文件 student.txt
	fp = fopen(FILENAME1, "r");
	if (NULL == fp) {
		printf("文件打开失败\n");
		exit(1);
	}

	// 创建链表头节点
	head = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == head) {
		printf("malloc error!!\n");
		exit(1);
	}
	// 头节点不保存数据,作为辅助指针
	head->stu = NULL;
	head->next = NULL;

	// 读取文件内容到链表中
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		Student *stu = (Student *)malloc(sizeof(Student));
		memset(stu, 0, sizeof(Student));
		if (NULL == stu) {
			printf("malloc error\n");
			exit(1);
		}
		// 读取每一行的学生信息,并保存在stu所指向的内存空间中
		getStudentInfo(buf, stu);
		//3.将stu结点插入有序链表中
		insertNodeByAge(head, stu);
	}
	//5.将链表中的结点信息写入student2.txt中
	writeToFile(head, FILENAME2);
	//6.销毁链表
	destoryListNode(head);
}

int main(void)
{
	test();
	return 0;
}