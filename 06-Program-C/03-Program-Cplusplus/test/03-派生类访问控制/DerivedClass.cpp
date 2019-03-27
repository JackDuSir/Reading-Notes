/*************************************************************************
	> File Name: DerivedClass.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 12时00分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	int mA;
protected:
	int mB;
private:
	int mC;
};

// 1. 公有（public）继承
class B : public A {
	void PrintB()
	{
		cout << mA << endl;		// 可访问基类 public 属性
		cout << mB << endl;		// 可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

class SubB : public B {
	void PrintSubB()
	{
		cout << mA << endl;		// 可访问基类 public 属性
		cout << mB << endl;		// 可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

void test01()
{
	B b;
	cout << b.mA << endl;		// 可访问基类 public 属性
	//cout << b.mB << endl;		// 不可访问基类 protected 属性
	//cout << b.mC << endl;		// 不可访问基类 private 属性
}

// 2. 私有（private）继承
class C : private A {
	void PrintC()
	{
		cout << mA << endl;		// 可访问基类 public 属性
		cout << mB << endl;		// 可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

class SubC : public C {
	void PrintSubC()
	{
		//cout << mA << endl;	// 不可访问基类 public 属性
		//cout << mB << endl;	// 不可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

void test02()
{
	C c;
	//cout << c.mA << endl;	// 不可访问基类 public 属性
	//cout << c.mB << endl;	// 不可访问基类 protected 属性
	//cout << c.mC << endl;	// 不可访问基类 private 属性
}

// 3. 保护（protected）继承
class D : protected A {
	void PrintD()
	{
		cout << mA << endl;		// 可访问基类 public 属性
		cout << mB << endl;		// 可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

class SubD : public D {
	void PrintSubD()
	{
		cout << mA << endl;		// 可访问基类 public 属性
		cout << mB << endl;		// 可访问基类 protected 属性
		//cout << mC << endl;	// 不可访问基类 private 属性
	}
};

void test03()
{
	D d;
	//cout << d.mA << endl;	// 不可访问基类 public 属性
	//cout << d.mB << endl;	// 不可访问基类 protected 属性
	//cout << d.mC << endl;	// 不可访问基类 private 属性
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}
