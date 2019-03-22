#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
//#include<>
using namespace std;

/*
set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

*/



//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
//上下限 就是lower_bound   upper_bound

//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//void printperson(const set<Person> &L)
//{
//	for (set<Person>::iterator it = L.begin(); it != L.end(); ++it)
//	{
//		cout << it->m_name << it->m_age << endl;
//	}
//}
//
//
//
//void test01()
//{
//
//	set<Person>L;
//	Person p1("马  云", 45);
//	Person p2("马华腾", 47);
//	Person p3("周宏伟", 43);
//	Person p4("李彦宏", 39);
//	Person p5("任正非", 45);
//	Person p6("王健林", 45);
//	L.insert(p1);
//
//	L.insert(p2);
//	L.insert(p3);
//	L.insert(p4);
//	L.insert(p5);
//	printperson(L);
//
//}
//
//
//



//void test()
//{
//	set<int> S;
//	S.insert(10);
//	S.insert(50);
//	S.insert(20);
//	S.insert(30);
//	S.insert(40);
//
//
//
//	for (set<int>::iterator it = S.begin(); it != S.end(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//	//用迭代器接收
//	S.lower_bound(3);
//
//}
//
//指定set排序规则
//仿函数数是一个类
class myCompare//指定排序规则时要加const
{
public:
	bool operator()( int v1, int v2) const
	{
		return v1 < v2;
	}
};

void print(set<int, myCompare> &s1)
{
	for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}




void test02()
{
	set<int, myCompare>s1;

	s1.insert(5);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(6);

	print(s1);

}

class Person
{
public:
	Person(string name, int age) :m_name(name), m_age(age)
	{}

	string m_name;
	int m_age;

};


//自定义数据类型指定排序规则时所有成员都得是const成员
class compare01
{
public:
	bool operator()(const Person &p1, const Person &p2)const
	{
		return p1.m_age > p2.m_age;
	}
};


void printperson(set<Person, compare01> &s)
{
	for (set<Person, compare01>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名:" << it->m_name << " 年龄:" << it->m_age << endl;
	}
}



void test03()
{
	set<Person, compare01> s;

	Person p1("马  云", 35);
	Person p2("马化腾", 36);
	Person p3("任正非", 37);
	Person p4("李彦宏", 38);
	Person p5("周宏伟", 39);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	printperson(s);
}





int main()
{


	//test();
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}