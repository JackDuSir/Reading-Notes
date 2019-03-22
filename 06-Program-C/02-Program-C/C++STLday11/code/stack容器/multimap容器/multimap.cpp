#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
//multimap


//ѧ����Ϣ
class staff;
//������Ϣ
void seek(map<int, staff> &M, int i);
//��ӡ��Ϣ
void myprint(map<int, staff> &m);
//������Ϣ
void insermes(map<int, staff> &M);
//ɾ����Ϣ
void deletemes(map<int, staff> &M, int ID);

//ѧ����Ϣ
class staff
{
public:
	staff(){};

	void setname(string name)
	{
		this->name = name;
	}
	void setage(int age)
	{
		this->age = age;
	}
	void setpone(long long pone)
	{
		this->pone = pone;	
	}
	void setwage(int wage)
	{
		this->wage = wage;
	}

	staff(string name, int age, long long pone, int wage)
	{
		this->name = name;
		this->age = age;
		this->pone = pone;
		this->wage = wage;
	}

	string name;
	int age;
	long long pone;
	int wage;
};


//��ӡ��Ϣ
void myprint(map<int, staff> &m)
{
	for (map<int, staff>::iterator it=m.begin(); it != m.end(); ++it)
	{
		cout << "ID:" << it->first << " ������" << it->second.name <<
			" �绰:" << it->second.pone << " ���䣺" << it->second.age <<
			" ����:" << it->second.wage << endl;
	}
}



//������Ϣ
void insermes(map<int, staff> &M)
{
	
	int i = 1;
	int over = 1;
	cout << "��������������0" << endl;
	while (over)
	{
		//int ID;
		string name;
		long long pone;
		int wage;
		int age;
		//cout << "������ѧ����ţ�";
		//cin >> ID;
		//cout << endl;
		
		cout << "������ѧ��������";
		cin >> name;

		cout << "������ѧ������:";
		cin >> age;
		if (age < 0 || age>200)
		{
			continue;
		}
		
		cout << "������绰:";
		cin >> pone;
	
		cout << "�����빤��:";
		cin >> wage;
		cout << "���������" << " ����:" << name << " �绰:" << pone <<
			" ����:" << age << " ����:"<<wage<<endl;
		//staff(string name, int age, long long pone, int wage)
		staff p1;
		p1.setname(name);
		p1.setage(age);
		p1.setpone(pone);
		p1.setwage(wage);
		M.insert(make_pair(i, p1));
			++i;
			cin >> over;
			if (over == 0)
			{
				over = 0;
			}
			else
			{
				over = 1;
			}
	}
}

//������Ϣ
void seek(map<int, staff> &M,int i)
{
	if (M.find(i) != M.end())
	{
		cout << "�ҵ�" << endl;

		if (M.find(i) != M.end())
		{
			cout << "ID:" << M.find(i)->first << " ����:" << M.find(i)->second.name <<
				" �绰:" << M.find(i)->second.pone << " ����:" << M.find(i)->second.age <<
				" ����:" << M.find(i)->second.wage<< endl;
		}		
	}
}


//ɾ����Ϣ
void deletemes(map<int, staff> &M,int ID)
{
	M.erase(ID);
}




void test01()
{
	map<int, staff> M;
	insermes(M);
	myprint(M);
	seek(M, 2);
	deletemes(M, 2);
	myprint(M);
}




int main(){


	//test();
	test01();
	system("pause");
	return EXIT_SUCCESS;
}