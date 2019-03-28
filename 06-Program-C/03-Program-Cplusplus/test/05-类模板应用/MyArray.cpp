/*************************************************************************
	> File Name: MyArray.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月28日 星期四 12时00分52秒
 ************************************************************************/

#include<iostream>
#include"MyArray.h"
using namespace std;

class Person {
public:
	Person(){}
	Person(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}
public:
	string mName;
	int mAge;
};

void PrintMyArrayInt(MyArray<int>& arr)
{
	int i = 0;
	for (i; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void PrintMyPerson(MyArray<Person>& personArr)
{
	int i = 0;
	for (i; i < personArr.getSize(); i++)
	{
		cout << "Name:" << personArr[i].mName << " Age:" << personArr[i].mAge << endl;
	}
}

void test()
{
	MyArray<int> myArrayInt(10);
	int i = 0;
	for (i; i < 9; i++)
	{
		myArrayInt.Push_back(i);
	}
	myArrayInt.Push_back(100);
	PrintMyArrayInt(myArrayInt);
	cout << "-----------------------" << endl;

	MyArray<Person> myArrayPerson(10);
	Person p1("德玛西亚", 30);
	Person p2("提莫", 20);
	Person p3("孙悟空", 18);
	Person p4("赵信", 15);
	Person p5("赵云", 24);
	myArrayPerson.Push_back(p1);
	myArrayPerson.Push_back(p2);
	myArrayPerson.Push_back(p3);
	myArrayPerson.Push_back(p4);
	myArrayPerson.Push_back(p5);
	PrintMyPerson(myArrayPerson);
}

int main()
{
	test();
	return 0;
}
