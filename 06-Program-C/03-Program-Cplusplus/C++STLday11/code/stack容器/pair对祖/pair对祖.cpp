#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void test()
{
	//
	pair<string, int>p(string("Tom"), 100);
	cout << "����" << p.first << endl;
	cout << "����" << p.second << endl;

	pair<string, int>p2 = make_pair("Jerry", 200);
	cout << "������" << p2.first << endl;
	cout << "���䣺" << p2.second << endl;

}

class Person
{
public:
	Person(string name, int age) :m_name(name), m_age(age)
	{}

	string m_name;
	int m_age;


};


void test01()
{
	Person p1("�����", 20);
	//Person p1("�����", 20);
	//Person p1("�����", 20);

	pair<int, Person>s1(10, p1);
	cout << s1.second.m_age << s1.second.m_name << endl;
	cout << s1.first << endl;


}



int main(){

	test01();
	//test();
	system("pause");
	return EXIT_SUCCESS;
}