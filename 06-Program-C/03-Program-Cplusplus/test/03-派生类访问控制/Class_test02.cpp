/*************************************************************************
	> File Name: Class_test02.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 14时52分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	Base():mParam(0){}
	void Print(){ cout << mParam << endl; }
public:
	int mParam;
};

class Derived : public Base {
public:
	Derived():mParam(10){}
	void Print()
	{
		// 在派生类中使用和基类的同名成员,显示使用类名限定符
		cout << Base::mParam << endl;
		cout << mParam << endl;
	}
	// 返回基类重名成员
	int &getBaseParam(){ return Base::mParam; }
public:
	int mParam;
};

int main()
{
	Derived derived;
	// 派生类和基类成员属性重名，子类访问成员默认是子类成员
	cout << derived.mParam << endl; // 10
	derived.Print();

	// 类外如何获得基类重名成员属性
	derived.getBaseParam() = 100;
	cout << "Base:mParam: " << derived.getBaseParam() << endl;

	return 0;
}
