#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"wall.h"
#include"snak.h"
#include"food.h"
#include<ctime>
#include<Windows.h>
#include<conio.h>


int main()
{
	srand(unsigned int(time(NULL)));
	wall p1;
	food f1(p1);
	p1.init();
	snak s1(p1, f1);
	bool isDeath = false;
	char preKey = NULL;
	s1.initsnak();
	f1.setFood();
	p1.showwall();

	while (!isDeath)
	{
		char key = _getch();
		if (preKey == NULL&&key == s1.LEFT&&key)
		{
			continue;
		}
		do
		{	//�����û�ֻ������wsad�Ľ�
			if (key == s1.LEFT || key == s1.RIGHT || key == s1.UP || key == s1.DOWN)
			{
				if ((key == s1.LEFT&&preKey == s1.RIGHT) ||
					(key == s1.RIGHT&&preKey == s1.LEFT) ||
					(key == s1.DOWN&&preKey == s1.UP) ||
					(key == s1.UP&&preKey == s1.DOWN)
					)
				{
					key = preKey;
				}
				else
				{
					preKey = key;//���ǳ�ͻ����
				}
				if (s1.movesnake(key))
				{
					system("cls");
					p1.showwall();
					Sleep(100);
				}
				else
				{
					isDeath = true;
					break;
				}
			}
			else
			{
				key = preKey;
			}
		}
		while (!_kbhit());//û�м��������ʱ��ͷ�����
	} 
	
	

	



	system("pause");
	return EXIT_SUCCESS;
}