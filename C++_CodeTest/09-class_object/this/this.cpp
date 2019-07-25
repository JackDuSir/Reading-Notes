/*************************************************************************
	> File Name: this.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月12日 星期一 17时55分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Box
{
	public:
		// 定义构造函数
		Box(double l=2.0, double b=2.0, double h=2.0)
		{
			cout << "Constructor called." << endl;
			lenght = l;
			breadth = b;
			height = h;
		}

		double Volume()
		{
			return lenght * breadth * height;
		}

		int compare(Box box)
		{
			return this->Volume() > box.Volume();
		}
	private:
		double lenght;
		double breadth;
		double height;
};

int main()
{
	Box Box1(3.3, 1.2, 1.5);
	Box Box2(8.5, 6.0, 2.0);

	if(Box1.compare(Box2))
	{
		cout << "Box2 is smaller than Box1" << endl;
	}
	else
	{
		cout << "Box2 is equal to or larger than Box1" << endl;
	}

	return 0;
}
