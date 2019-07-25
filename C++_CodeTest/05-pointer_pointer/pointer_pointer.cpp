/*************************************************************************
	> File Name: pointer_pointer.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月09日 星期五 16时57分17秒
 ************************************************************************/

#include<iostream>
using namespace std;


void func(int *p);

int main()
{
	int b = 10;
	int *p;
	p = &b;
	func(p);
	cout << "*P values: " << *p << endl;
	cout << "P values: " << p << endl;

	return 0;
}

void func(int *p)
{
	*p = 20;
}
