#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
天生棋局。有两个函数原型的题目可任意实现一个
1.	 传入一个n 在堆空间中产生n*n方格的棋盘
int ** createBoard(int n);
int   createBoard1(int ***p,int n);
2.	 N颗棋子随机落在棋盘上<需要防止落在同一位置>
int  initBoard(int **p,int n);
3.	 打印棋盘
int  printBoard(int **p,int n);
如果有两颗棋子落同一行或者同一列 输出好棋
否则 输出 不是好棋
将棋局中的棋子打印出来 空位用O
有旗子的用X表示
4.	销毁棋盘
int  destroyBoard(int **p,int n);
int  destroyBoard1(int ***p,int n);

*/


/*
函数功能: 在堆空间中创建 n * n 的二维空间
函数参数:n 数组维数
函数返回值: 成功 返回 空间地址, 失败返回 NULL
*/
int ** createBoard(int n)
{
	int i = 0;
	int ** tmp = (int **)malloc(sizeof(int *) * n);
	if (NULL == tmp) {
		printf("申请内存失败");
		return NULL;
	}

	for (i = 0; i < n; ++i) {
		tmp[i] = (int *)malloc(sizeof(int) * n);
		if (NULL == tmp[i]) {
			printf("申请内存失败");
			return NULL;
		}
		memset(tmp[i], 0, sizeof(int) * n);
	}

	return tmp;
}

int   createBoard1(int ***p, int n)
{
	int i = 0;
	int ** tmp = (int **)malloc(sizeof(int *) * n);
	if (NULL == tmp) {
		printf("申请内存失败");
		return NULL;
	}

	for (i = 0; i < n; ++i) {
		tmp[i] = (int *)malloc(sizeof(int) * n);
		if (NULL == tmp[i]) {
			printf("申请内存失败");
			return NULL;
		}
		memset(tmp[i], 0, sizeof(int) * n);
	}
	*p = tmp;	//间接赋值,
}

/*
使用随机数初始化棋盘
*/
int  initBoard(int **p, int n)
{
	int i = 0;
	int randx = 0;
	int randy = 0;

	srand((unsigned int)time(NULL));

	for (i = 0; i < n; ++i) {
		randx = rand() % n;
		randy = rand() % n;
		if (p[randx][randy] == 0) {
			// 判断此位置是否已放入棋子,如果没放,则放入,如果已经存在 则 棋子数减 1
			p[randx][randy] = 1;
		} else {
			i--;
		}
	}
	return 0;
}

/*
函数功能: 打印棋盘
函数参数:
函数返回值: 
*/

int  printBoard(int **p, int n)
{
	int  i = 0;
	int j = 0;
	int flag = 0;
	int sumline = 0, sumrow = 0;	// 记录横行和纵行 棋子个数
	for (i = 0; i < n; ++i) {
		sumline = 0;
		sumrow = 0;
		for (j = 0; j < n; ++j) {
			if (p[i][j] == 0){
				printf("%c  ",'O');
			}
			else {
				printf("%c  ", 'X');
			}
			sumline += p[i][j];
			sumrow += p[j][i];
		}
		printf("\n");
		if (sumrow >= 2 || sumline >= 2) {
			flag = 1;
		}
	}
	if (1 == flag){
		printf("\n------好棋--------\n");
	}
	else {
		printf("\n------不是好棋--------\n");
	}
	
return		0;
}

/*
函数功能:销毁棋盘,释放堆空间
函数参数:
函数返回值: 
*/
int  destroyBoard(int **p, int n)
{
	if (NULL == p)
	{
		return -1;
	}
	for (int i = 0; i < n; ++i) {
		if (NULL != p[i]) {
			free(p[i]);
			p[i] = NULL;
		}
	}
	free(p);
	p = NULL;
	return 0;
}

void test()
{
	int num = 0;
	int ** array = NULL;

	printf("请输入数组维数:");
	scanf("%d", &num);

	array = createBoard(num);
	if (NULL == array) {
		printf("创建二维空间失败\n");
		exit(1);
	}
	initBoard(array, num);
	printBoard(array, num);
	destroyBoard(array, num);
}

void test2()
{
	int num = 0;
	int ** array = NULL;

	printf("请输入数组维数:");
	scanf("%d", &num);
	createBoard1(&array, num);
	initBoard(array, num);
	printBoard(array, num);
	destroyBoard(array, num);
}
int main(void)
{
	test();
	return 0;
}