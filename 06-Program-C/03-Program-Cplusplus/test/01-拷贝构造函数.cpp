/*************************************************************************
	> File Name: 01-拷贝构造函数.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 六  3/23 19:09:58 2019
 ************************************************************************/
/*
拷贝构造函数的调用时机
对象以值传递的方式传给函数参数
函数局部对象以值传递的方式从函数返回(vs debug模式下调用一次拷贝构造，qt不调用任何构造)
用一个对象初始化另一个对象
*/
#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "no param contructor!" << endl;
		mAge = 10;
	}
	Person(int age) 
		cout << "param contructor!" << endl;
	}
	Person(const Person& person) {
		cout << "copy contructor!" << endl;
		mAge = person.mAge;
	}
	~Person() {
		cout << "destructor!" << endl;
	}
public:
	int mAge;
}

// 1. 就对象初始化新对象
void test01()
{
	Person p(10);
	Person p1(p);
	Person p2 = Person(p);
	Person p3 = p;	// 相当于 Person p2 = Person(p);
}

// 2. 传递的参数是普通对象，函数参数也是普通对象，传递将会调用拷贝构造
void doBussiness(Person p){}

void test02()
{
	Person p(10);
	doBussiness(p);
}

// 3. 函数返回局部对象
Person MyBussiness()
{
	Person p(10);
	cout << "局部 p:" << (int *)&p << endl;
	return p;
}

void test03()
{
	//vs release、qt下没有调用拷贝构造函数
	//vs debug下调用一次拷贝构造函数
	Person p = MyBussiness();
	cout << "局部 p:" << (int *)&p << endl;
}

int main()
{
	test01();
	cout << "----------------------------" << endl;
	test02();
	cout << "----------------------------" << endl;
	test03();
	return 0;
}
