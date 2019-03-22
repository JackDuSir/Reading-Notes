#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
//#include<al>
#include<string>
#include<algorithm>
using namespace std;


class Person
{
public:
	Person(string naem, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;

};

void test()
{
	vector<vector<int>> v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i);
		v2.push_back(i * 10);
		v3.push_back(i * 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)
		{

			//*vit就是vector<int>中的int
			cout << *vit << ' ';
		}
		cout << endl;
	}
}




void test01()
{
	vector<vector<int>> v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i );
		v2.push_back(i * 10);
		v3.push_back(i * 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

		//vector容器中的iterator迭代器
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<int>::iterator v1 = (*it).begin(); v1 != (*it).end(); ++v1)
		{
			cout << *v1 << ' ';
		}
		cout << endl;
	}
}

class Person01
{
public:
	Person01(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void show()
	{
		cout << "姓名：" << this->name<<endl;
		cout << "年龄：" << this->age << endl;
	}

	string name;
	int age;

};

void print(Person01 *p)
{
	cout << p->name<<" ";
	cout << p->age << endl;
}



void test03()
{
	vector<Person01 *> v;

	Person01 *p1 = new Person01{ "马云", 30 };
	Person01 *p2 = new Person01{ "马化腾", 30 };
	Person01 *p3 = new Person01{ "李彦宏", 30 };
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for_each(v.begin(), v.end(), print);
	
}




int main(){

	
	//test();
	//test01();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}