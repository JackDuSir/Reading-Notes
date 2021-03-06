#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Content
{
	char *key;
	char *val;


};
//判断行数是否有效
int ValidLine(char *buf)
{
	if (buf[0] == '\n' || buf[0] == '#' || (strchr(buf, ':') == NULL))
	{
		return 0;
	}

	return 1;
}


//获取有效行数
void GetLineNumber(FILE *file,int *line)
{
	if (NULL == file)
	{
		return;
	}
	int i = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, file) != NULL)
	{
		if (ValidLine(buf))
		{
			++i;
		}
	}
	memset(buf, 0, 1024);
	fseek(file, 0, SEEK_SET);
	*line = i;
}

//获取文件内容到结构体
void GainContent(struct Content ***myContent, FILE * fileCont, int len)
{
	if (NULL == fileCont)
	{
		return;
	}
	if (len == 0)
	{
		printf("文件为空\n");
		return;
	}
	struct Content **myCont = malloc(sizeof(struct Content *)*len);
	memset(myCont, 0, sizeof(struct Content *)*len);
	char buf[1024] = { 0 };
	int index = 0;
	char *pos = NULL;
		while (fgets(buf, 1024, fileCont) != NULL)
		{
			if (ValidLine(buf))
			{
				myCont[index] = malloc(sizeof(struct Content));
				pos = strchr(buf, ':');
				//根据内容开辟相应大小的空间
				myCont[index]->key = malloc(sizeof(char)*(pos - buf));

				char *pp = NULL;
				char *pp2 = NULL;
				
				strncpy(myCont[index]->key, buf, pos - buf);
				pp = myCont[index]->key + (pos - buf);
				//手动在每一个后面添加\0
				*pp = '\0';
				//根据内容动态开辟一块内存
				myCont[index]->val = malloc(sizeof(char)*strlen(pos + 1));
				strncpy(myCont[index]->val, pos+1, strlen(pos + 1));

				//这里为什么是最后一个有效数字为什么是三个？？
				pp2 = myCont[index]->val + strlen(pos + 1);
				*pp2 = '\0';

				++index;
			}	
			memset(buf, 0, 1024);
		}

	*myContent = myCont;
	fclose(fileCont);
}


void freeContent(struct Content ** myContent, int line)
{
	if (NULL == myContent)
	{
		return;
	}
	for (int i = 0; i < line; ++i)
	{
		if (myContent[i]->key!= NULL)
		{
			free(myContent[i]->key);
			myContent[i]->key = NULL;
		}
		if (myContent[i]->val != NULL)
		{
			free(myContent[i]->val);
			myContent[i]->val = NULL;
		}
		if (myContent[i] != NULL)
		{
			free(myContent[i]);
			myContent[i]= NULL;
		}
	}
	free(myContent);
	myContent = NULL;

}




void test01()
{
	struct Content **myContent = NULL;
	FILE *file = fopen("E:/传智博客就业班/c提高05day/源码/config.ini", "r");
	int line = 0;
	GetLineNumber(file, &line);
	GainContent(&myContent, file, line);

	for (int i = 0; i < line; ++i)
	{
		printf("%s:%s",myContent[i]->key, myContent[i]->val);
	}

	freeContent(myContent, line);
}





void main()
{
	test01();
	system("pause");
}