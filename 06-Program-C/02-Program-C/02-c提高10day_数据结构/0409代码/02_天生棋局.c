#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
������֡�����������ԭ�͵���Ŀ������ʵ��һ��
1.	 ����һ��n �ڶѿռ��в���n*n���������
int ** createBoard(int n);
int   createBoard1(int ***p,int n);
2.	 N�������������������<��Ҫ��ֹ����ͬһλ��>
int  initBoard(int **p,int n);
3.	 ��ӡ����
int  printBoard(int **p,int n);
���������������ͬһ�л���ͬһ�� �������
���� ��� ���Ǻ���
������е����Ӵ�ӡ���� ��λ��O
�����ӵ���X��ʾ
4.	��������
int  destroyBoard(int **p,int n);
int  destroyBoard1(int ***p,int n);

*/


/*
��������: �ڶѿռ��д��� n * n �Ķ�ά�ռ�
��������:n ����ά��
��������ֵ: �ɹ� ���� �ռ��ַ, ʧ�ܷ��� NULL
*/
int ** createBoard(int n)
{
	int i = 0;
	int ** tmp = (int **)malloc(sizeof(int *) * n);
	if (NULL == tmp) {
		printf("�����ڴ�ʧ��");
		return NULL;
	}

	for (i = 0; i < n; ++i) {
		tmp[i] = (int *)malloc(sizeof(int) * n);
		if (NULL == tmp[i]) {
			printf("�����ڴ�ʧ��");
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
		printf("�����ڴ�ʧ��");
		return NULL;
	}

	for (i = 0; i < n; ++i) {
		tmp[i] = (int *)malloc(sizeof(int) * n);
		if (NULL == tmp[i]) {
			printf("�����ڴ�ʧ��");
			return NULL;
		}
		memset(tmp[i], 0, sizeof(int) * n);
	}
	*p = tmp;	//��Ӹ�ֵ,
}

/*
ʹ���������ʼ������
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
			// �жϴ�λ���Ƿ��ѷ�������,���û��,�����,����Ѿ����� �� �������� 1
			p[randx][randy] = 1;
		} else {
			i--;
		}
	}
	return 0;
}

/*
��������: ��ӡ����
��������:
��������ֵ: 
*/

int  printBoard(int **p, int n)
{
	int  i = 0;
	int j = 0;
	int flag = 0;
	int sumline = 0, sumrow = 0;	// ��¼���к����� ���Ӹ���
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
		printf("\n------����--------\n");
	}
	else {
		printf("\n------���Ǻ���--------\n");
	}
	
return		0;
}

/*
��������:��������,�ͷŶѿռ�
��������:
��������ֵ: 
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

	printf("����������ά��:");
	scanf("%d", &num);

	array = createBoard(num);
	if (NULL == array) {
		printf("������ά�ռ�ʧ��\n");
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

	printf("����������ά��:");
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