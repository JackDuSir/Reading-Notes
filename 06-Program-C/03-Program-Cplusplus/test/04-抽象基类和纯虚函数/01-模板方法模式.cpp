/*************************************************************************
	> File Name: 01-模板方法模式.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 17时35分28秒
 ************************************************************************/
/*
 * 建立公共接口目的是为了将子类公共的操作抽象出来，可以通过一个公共接口来操纵一组类，且这个公共接口不需要事先(或者不需要完全实现)。可以创建一个公共类.
 */
#include<iostream>
using namespace std;

// 抽象制作饮品
class AbstractDrinking {
public:
	// 烧水
	virtual void Boil() = 0;
	// 冲泡
	virtual void Brew() = 0;
	// 倒入杯中
	virtual void PourInCup() = 0;
	// 加入辅料
	virtual void PutSomething() = 0;

	// 规定流程
	void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

// 制作咖啡
class Coffee : public AbstractDrinking {
public:
	virtual void Boil()
	{
		cout << "煮农夫山泉！" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡！" << endl;
	}
	virtual void PourInCup()
	{
		cout << "将咖啡倒入杯中！" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入牛奶！" << endl;
	}
};

// 制作茶水
class Tea : public AbstractDrinking {
public:
	virtual void Boil()
	{
		cout << "煮自来水！" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶！" << endl;
	}
	virtual void PourInCup()
	{
		cout << "将茶水导入杯中！" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入柠檬！" << endl;
	}
};

// 业务函数
void DoBussiness(AbstractDrinking *drink)
{
	drink->MakeDrink();
	delete drink;
}

void test()
{
	DoBussiness(new Coffee);
	cout << "-------------------" << endl;
	DoBussiness(new Tea);
}

int main()
{
	test();
	return 0;
}
