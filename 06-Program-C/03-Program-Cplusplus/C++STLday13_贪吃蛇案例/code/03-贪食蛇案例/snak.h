#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

class snak
{
public:
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
	
	snak(wall & mywall,food & myfood );
	
	struct point
	{
		int snakx;
		int snaky;
		point *next;
	};

	//��ʼ��
	void initsnak();

	//����
	void destroysnak();
	
	//��ӽڵ�
	void addnode(int x,int y);
	//ɾ��β�ڵ�
	void delettepoint();
	//�ƶ�
	bool movesnake(char a);


	wall & mywall;
	point *head;
	food &myfood;
	bool isRool;//�ж�ѭ��ָʾ
};


