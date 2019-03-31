#include"snak.h"


snak::snak(wall  & mywall, food &myfood) :mywall(mywall), myfood(myfood)
{
	this->head = NULL;
}
//��ʼ��
void snak::initsnak()
{
	destroysnak();
	addnode(5, 4);
	addnode(5, 5);
	addnode(5, 6);
}

	//����
void snak::destroysnak()
{
	point * pcur = NULL;
	while (head != NULL)
	{
		pcur = head->next;
		delete head;
		head = pcur;
	}
	
}

	//��ӽڵ�
void snak::addnode(int x,int y)
{
	point * newpoit = new point;
	newpoit->snakx = x;
	newpoit->snaky = y;
	newpoit->next = NULL;

	if (head != NULL)
	{
		mywall.getseat(head->snakx, head->snaky, '=');
	}

	newpoit->next = head;
	head = newpoit;
	mywall.getseat(head->snakx, head->snaky, '@');
}

//ɾ��β�ڵ�
void snak::delettepoint()
{
	if (head != NULL && head->next != NULL)
	{
		point *pre = head;
		point *pcur = head->next;

		while (pcur->next != NULL)
		{
			pcur = pcur->next;
			pre = pre->next;
		}

		mywall.getseat(pcur->snakx, pcur->snaky, ' ');
		delete pcur;
		pcur = NULL;
		pre->next = NULL;
	}
	
}

bool snak::movesnake(char a)
{
	int x = head->snakx;
	int y = head->snaky;
	switch (a)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	//�ж� �������һ����������β�ͣ���Ӧ������
	point *pCur = head->next;
	point *pPre = head;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->snakx == x && pCur->snaky == y)
	{
		isRool = true;
	}
	else
	{
		//�ƶ�ʧ��
		if (mywall.setplace(x, y) == '*' || mywall.setplace(x, y) == '=')
		{
			addnode(x, y);
			delettepoint();
			system("cls");
			mywall.showwall();
			cout << "GAME OVER!!" << endl;
			return false;
		}	
	}



	//�ƶ����������
	//�Ե�����
	if (mywall.setplace(x, y) == '#')
	{
		addnode(x, y);
		myfood.setFood();
	}
	//û�гԵ�ʳ��
	else
	{
		addnode(x, y);
		delettepoint();
		if (isRool == true)
		{
			mywall.getseat(x, y, '@');
		}
	}

	return true;
}