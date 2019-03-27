/*************************************************************************
	> File Name: 01-多继承.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 16时35分48秒
 ************************************************************************/
/*
 * 继承会带来一些二义性的问题， 如果两个基类中有同名的函数或者变量，那么通过派生类对象去访问这个函数或变量时就不能明确到底调用从基类1继承的版本还是从基类2继承的版本？
 * 解决方法就是显示指定调用那个基类的版本。
 *
 */
#include<iostream>
using namespace std;

class Base1 {
public:
	void func1(){ cout << "Base1::func1" << endl; }
};

class Base2 {
public:
	void func1(){ cout << "Base2::func1" << endl; }
	void func2(){ cout << "Base2::func2" << endl; }
};

// 派生类继承Base1、Base2
class Derived : public Base1, public Base2 {};

int main()
{
	Derived derived;
	// func1是从Base1继承来的还是从Base2继承来的？
	//derived.func1();
	derived.func2();

	// 解决歧义:显示指定调用那个基类的func1
	derived.Base1::func1();
	derived.Base2::func1();

	return 0;
}
