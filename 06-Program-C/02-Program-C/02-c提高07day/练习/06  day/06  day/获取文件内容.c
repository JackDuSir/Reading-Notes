#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getfile()
{
	FILE *file = fopen("", "r");
	if ( NULL == file )
	{
		return;
	}
	char buf[1024] = { 0 };
	while (fgets(buf,1024,file)!=NULL)
	{
		//把每一行的换行替换为\0
		buf[strlen(buf - 1)] = '\0';
		char *temp = strtok(buf, " ");
		printf("成员年龄为%d", atoi(temp));
		int i = 1;
		float j = (float)atoi(temp);
		while (temp)
		{
			if (temp)
			{
				temp = strtok(NULL, " ");
				printf("%d ", atoi(temp));
				j += (float)atoi(temp);
				++i;
			}
			printf("\n");
		}
		printf("家庭成员平均年龄%f", j / i);
	}
}




void test01()
{
	
	getfile();



}

void main()
{



}


