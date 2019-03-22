#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void deletestr(char *str)
{
	char *pre = str;
	char buf[255] = { 0 };
	while ((*pre) != '\0')
	{
		int i = (*pre);
		buf[i] = (*pre);
		pre++;
	}
	char temp[255];
	int j = 0;
	for (unsigned int i = 0; i <255; ++i)
	{
		if (buf[i] != 0)
		{
			printf("%c", buf[i]);
			temp[j] = buf[i];
			j++;
		}		
	}
	printf("\n");
	temp[j + 1] = '\0';
	for (unsigned int i = 0; i < strlen(temp); ++i)
	{
		printf("%c", temp[i]);
	}
	printf("\n");
}





int main()
{

	char str[] = "000000000";
	deletestr(str);
	system("pause");

}