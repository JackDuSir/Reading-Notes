#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<ctime>
#include<string>
using namespace std;


//multimap ����
//��˾������Ƹ�� 5 ��Ա����5 ��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ�� Multimap ������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
class staff
{
public:
	staff(string name, int age, long long pone, int wage) : m_name(name), m_age(age), m_pone(pone), m_wage(wage)
	{}

	string m_name;
	int m_age;
	long long m_pone;
	int m_wage;

};
//��������
void inser(multimap<int, staff>&M,int max)
{
	for (int i = 0; i < max; ++i)
	{
		int m_i = rand() % 10;
		char name[64] = {0};
		long long pone = 0;
		int wage = 0;
		int age = 0;
		sprintf(name, "name_%d", (rand() % 10));
		string m_name = name;
		pone = (rand() % 10 + 15556930460);
		wage = (rand() % 10 + 1) * 1000;
		age = rand() % 10 + 30;
		staff p1(m_name, age, pone, wage);
		M.insert(make_pair((rand() % 4), p1));
	}
}


//��ӡ
void print(staff & s)
{
	cout << "����:" << s.m_name 
		<< "����:" << s.m_age 
		<< "�绰:" << s.m_pone 
		<< "����:" <<s.m_wage<< endl;
}

//������ӡ
void printmultimap(multimap<int, staff> &M)
{
	for (multimap<int, staff>::iterator it = M.begin(); it != M.end(); ++it)
	{
		cout << "����" << it->second.m_name << " ����:" << it->second.m_age << " �绰:" << it->second.m_pone
			<< " нˮ:" << it->second.m_wage <<" ����:"<<it->first<< endl;
	}
}




void test()
{
	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	multimap<int, staff>M;
	inser(M, 5);
	cout << "ȫ��Ա����Ϣ" << endl;
	printmultimap(M);
	//for (multimap<int, staff>::iterator it = M.begin(); it != M.end(); ++it)
	//{
	//	
	//
	//}
	
	//M.find(3);
	if (M.find(3) != M.end())
	{
		cout << "-------------------�ҵ�------------------" << endl;
		cout << "����" << M.find(3)->second.m_name << " ����:" << M.find(3)->second.m_age << " �绰:" << M.find(3)->second.m_pone
			<< " нˮ:" << M.find(3)->second.m_wage << " ����:" << M.find(3)->first << endl;
	}
	else
	{
		cout << "-------------------δ�ҵ�------------------" << endl;
	}
}



int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}