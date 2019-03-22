#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>

using namespace std;

/*
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����
3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�


3.6.4.3 list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
3.6.4.5 list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�
3.6.4.6 list��ת����
reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
*/

//�Զ���������
class Person
{
public:
	Person(string name, int age, int stature)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_stature = stature;
	}

	string m_name;
	int m_age;
	int m_stature;//���
};

//����ص�����
bool personcomper(Person &p1,Person &p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_stature < p2.m_stature;
	}
	else
	{
		return p1.m_age > p2.m_age;
	}

}

//��ӡ����
void printpreson(list<Person> &L)
{
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << "������" <<it->m_name << " ���䣺" <<it->m_age << " ��ߣ�" <<it->m_stature << endl;
	}
}


void test()
{
	list<Person>L;
	Person p1("��  ��", 45, 160);
	Person p2("����", 47, 178);
	Person p3("�ܺ�ΰ", 43, 177);
	Person p4("�����", 39, 185);
	Person p5("������", 45, 180);
	Person p6("������", 45, 170);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	//��ת��ı������е�����
	L.sort(personcomper);
	cout << "-------------��תǰ--------------" << endl;
	printpreson(L);//��ӡ����

	//L.remove(p1);

	cout << "��ʼԪ�� ������" << L.front().m_name << " ���䣺" <<
		L.front().m_age << "���" << L.front().m_stature << endl;
	cout << "���Ԫ�� ������" << L.back().m_name << " ���䣺" <<
		L.back().m_age << "���" << L.back().m_stature << endl;
	cout << "-------------��ת��--------------" << endl;
	L.reverse();
	printpreson(L);//��ӡ����
	cout << "��ʼԪ�� ������" << L.front().m_name << " ���䣺" << 
		L.front().m_age << "���" << L.front().m_stature << endl;
	cout << "���Ԫ�� ������" << L.back().m_name << " ���䣺" <<
		L.back().m_age << "���" << L.back().m_stature << endl;

	

}


void printint(list<int> &L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;

}



void test01()
{
	list<int>L;
	
	for (int i = 0; i < 5; ++i)
	{
		L.push_back(i);
	}
	for (int i = 0; i < 1000; ++i)
	{
		L.push_front((i * 10));
	}
	//cout << "L�Ĵ�С��" << sizeof(L) << endl;
	//printint(L);
	//L.sort();
	//printint(L);
	//L.pop_front();
	//cout << "L�Ĵ�С��"<<sizeof(L) << endl;
	//printint(L);
	
}




int main(){


	test();
	//test01();
	system("pause");
	return EXIT_SUCCESS;
}