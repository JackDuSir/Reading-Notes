#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int ** createBoard(int n)//动态分配空间
{
	int **a = malloc(sizeof(int *) * n);

	for (int i = 0; i < n; ++i)
	{
		a[i] = malloc(sizeof(int)*n);
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = 0;
		}
	}
	return a;
}

int  printBoard(int **p, int n)//打印棋盘
{
	int **b = p;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%4d", b[i][j]);
		}
		printf("\n");
	}
	
	
	int num;
	for (int i = 0; i < n; ++i)
	{
		num = 0;
		for (int j = 0; j < n; ++j)
		{
			num += b[i][j];	
		}	
	}
	if (num >= 2)
	{
		printf("好棋\n");
	}
	else
	{
		printf("不是好棋\n");
	}

	int eum;
	for (int i = 0; i < n; ++i)
	{
		eum = 0;
		for (int j = 0; j < n; ++j)
		{
			eum += b[j][i];
		}	
	}
	if (eum >= 2)
	{
		printf("好棋\n");
	}

	else
	{
		printf("不是好棋\n");
	}
	
	return 1;
}

//产生随机数在棋盘落子
int random(int n)
{
	
	time_t ts;
	unsigned int data = (unsigned int)time(&ts);
	srand(data);
	return rand() % n;
}

int  initBoard(int **p, int n)//将
{

	int **a = p;

	while (n > 0)
	{
		int i = 0;
		int j = 0;

		
		i = random(n);
		j = random(n);
		n--;
		if (a[i][j] == 1)
		{
			continue;
		}
		else
		{
			a[i][j] = 1;
		}
	}
	
	return 1;
}

//销毁棋盘
int  destroyBoard(int **p, int n)
{
	int **a = p;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != NULL)
		{
			free(a[i]);
		}
	}
	free(a);

	return 1;
}



int main()
{
	int **b = createBoard(4);
	int i = initBoard(b, 8);
	printf("-------------------\n");
	printBoard(b, 4);
	int j = destroyBoard(b, 4);
	system("pause");

}