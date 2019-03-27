/*************************************************************************
	> File Name: SizeofClass.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月27日 星期三 12时19分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Aclass {
public:
	int mA;
	int mB;
};

class Bclass : public Aclass {
public:
	int mC;
};

class Cclass : public Bclass {
public:
	int mD;
};

void test()
{
	cout << "A size: " << sizeof(Aclass) << endl;
	cout << "B size: " << sizeof(Bclass) << endl;
	cout << "C size: " << sizeof(Cclass) << endl;
}

int main()
{
	test();
	return 0;
}
