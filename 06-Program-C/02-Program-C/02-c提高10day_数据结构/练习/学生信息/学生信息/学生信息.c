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

//链表节点
typedef struct _listNode
{
	//一个指向包含学生信息的结构体指针
	Student *stu;
	//一个指向本结构体的指针
	struct _listNode *next;
}ListNode;

/*
函数功能:从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。
函数参数:studentInfo：指向包含学生name和age的一个字符串。
stu：指向用于保存学生信息的结构体。
函数返回值: 成功返回0，失败返回-1。
*/

//把字符拷贝到结构体中的函数
int  getStudentInfo(const char *studentInfo, Student *stu)

{
	//判断传入参数的有效性
	if (NULL == studentInfo || NULL == stu)
	{
		return - 1;
	}
	//定义一个char型指针，让他指向空
	const char *pbegin = NULL;
	//定义两个指针让它移动
	const char *pend = NULL;
	char buf[32] = { 0 };
	//处理字符串，得到学生信息name和age
	//name= haha age=23
	//查找字符串中"="出现的位置
	//让指针pbgin指向字符串中=位置
	//strchar 函数是找到字符串字符首次出现的位置
	pbegin = strchr(studentInfo, '=');
	pbegin++;//去除=
	//去除空格
	while (*pbegin == ' ')
		pbegin++;
	pend = pbegin;
	//定一个辅助指针，让他从当前位置开始向后移动
	while (*pend !=' ')//找到下一个空格之前
	{
		pend++;//
		strncpy(stu->name, pbegin, pend - pbegin);//找到空格之前就是找到了名字的尾部
		//然后让当前指针减去开始指针得到一个整数，整数长度就是名字长度
		//最后把它拷贝到stu->name中
		//让开始的指针指向最后

		//让pbegin指向从pend开始第一次出现=的位置
		pbegin = strchr(pend, '=');
		//去除空格
		pbegin++;
		while (*pbegin == ' ')//去除空格，找到第一个不为空格的字符
		{
			pbegin++;
		}

		sscanf(*pbegin, "%d", &stu->age);

		return 0;		
	}
	
}

/*
函数功能:将学生的信息按age从大到小的顺序插入到链表中
函数参数:
函数返回值: 成功 0 ,失败 -1
*/

//
int insertNodeByAge(ListNode *head, Student *stu)
{
	//判断传入结构体的有效性
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
		//从大到小排序
		if (pCur->stu->age > stu->age)
		{
			//判断链表节点age与链表中age的大小
			pPre = pCur;
			pCur = pCur->next;
		}
		else
		{
			break;//找到比待插入节点age小的链表节点
			//带插入节点需要插入到该节点前
		}

	}
	//新节点插入链表
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
函数功能:将链表结点中学生的信息写入文件中
函数参数:
函数返回值:
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
		//把结构体中的内容格式化写到文件中
		fprintf(fp, "name=%s age=%d", pCur->stu->name, pCur->stu->age);
		pCur = pCur->next;
	}
	//写完之后关闭文件
	fclose(fp);
	return 0;
}


/*
函数功能:销毁链表,释放表空间
函数参数:
函数返回值:
*/
//销毁链表我们只需要链表信息结构体
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