/*************************************************************************
	> File Name: Class_test.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 14时17分59秒
 ************************************************************************/
/*
 * 在子类类对象时，构造函数与析构函数的执行顺序为：
 * 父类 --> 对象成员 --> 子类类
 *
 * 以下代码构造调用顺序：A --> B --> D --> C
 */

#include<iostream>
using namespace std;

class D {
public:
	D()
	{
		cout << "D 类构造函数！" << endl;
	}
	~D()
	{
		cout << "D 类析构函数！" << endl;
	}
};

class A {
public:
	A()
	{
		cout << "A 类构造函数！" << endl;
	}
	~A()
	{
		cout << "A 类析构函数！" << endl;
	}
};

class B : public A {
public:
	B()
	{
		cout << "B 类构造函数！" << endl;
	}
	~B()
	{
		cout << "B 类析构函数！" << endl;
	}
};

class C : public B {
public:
	C()
	{
		cout << "C 类构造函数！" << endl;
	}
	~C()
	{
		cout << "C 类析构函数！" << endl;
	}
public:
	D c;
};

void test()
{
	C c;
}

int main()
{
	test();
	return 0;
}

