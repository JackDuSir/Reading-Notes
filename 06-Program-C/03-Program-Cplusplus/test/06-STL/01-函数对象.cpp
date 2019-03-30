/*************************************************************************
	> File Name: 01-函数对象.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月30日 星期六 15时08分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

// 函数对象是重载了函数调用符号的类
class MyPrint {
public:
	MyPrint()
	{
		m_Num = 0;
	}
	int m_Num;

public:
	void operator() (int num)
	{
		cout << num << endl;
		m_Num++;
	}
};

// 函数对象
// 重载了()操作符的类实例化的对象，可以像普通函数那样调用,可以有参数 ，可以有返回值
void test01()
{
	MyPrint myPrint;
	myPrint(20);
}

// 函数对象超出了普通函数的概念，可以保存函数的调用状态
void test02()
{
	MyPrint myPrint;
	myPrint(20);
	myPrint(20);
	myPrint(20);
	cout << myPrint.m_Num << endl;
}

void DoBusiness(MyPrint print, int num)
{
	print(num);
}

// 函数对象做为参数
void test03()
{
	// 参数1：匿名函数对象
	DoBusiness(MyPrint (), 30);
}

int main()
{
	test01();
	cout << "------------------------" << endl;
	test02();
	cout << "------------------------" << endl;
	test03();

	return 0;
}
