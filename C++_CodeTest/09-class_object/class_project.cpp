/*************************************************************************
	> File Name: class_project.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月12日 星期一 15时18分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Box
{
	public:
		double length;	// 长度
		double breadth;	// 宽度
		double height;	// 高度
};

int main()
{
	Box Box1;	// 声明 Box1，类型为 Box
	Box Box2;
	double volume = 0.0;		// 用于存储体积

	// Box1 详述
	Box1.length = 5.0;
	Box1.breadth = 6.0;
	Box1.height = 7.0;

	// Box2 详述
	Box2.length = 10.0;
	Box2.breadth = 12.0;
	Box2.height = 13.0;

	// Box1 的体积
	volume = Box1.length * Box1.breadth * Box1.height;
	cout << "Box1 的体积：" << volume << endl;

	// Box2 的体积
	volume = Box2.length * Box2.breadth * Box2.height;
	cout << "Box2 的体积：" << volume << endl;

	return 0;
}

