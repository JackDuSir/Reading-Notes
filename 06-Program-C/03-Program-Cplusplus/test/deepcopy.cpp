/*************************************************************************
	> File Name: deepcopy.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月25日 星期一 14时53分47秒
 ************************************************************************/
/*
 * 同一类型的对象之间可以赋值，使得两个对象的成员变量的值相同，两个对象仍然是独立的两个对象，这种情况被称为浅拷贝.
 * 一般情况下，浅拷贝没有任何副作用，但是当类中有指针，并且指针指向动态分配的内存空间，析构函数做了动态内存释放的处理，会导致内存问题。
 * 当类中有指针，并且此指针有动态分配空间，析构函数做了释放处理，往往需要自定义拷贝构造函数，自行给指针动态分配空间，深拷贝。
 */
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class Person {
	public:
		Person(char *name, int age)
		{
			pName = (char *)malloc(strlen(name) + 1);
			strcpy(pName, name);
			mAge = age;
		}
		// 增加拷贝构造函数
		Person(const Person &person)
		{
			pName = (char *)malloc(strlen(person.pName) + 1);
			strcpy(pName, person.pName);
			mAge = person.mAge;
			cout << "pName:" << pName << " mAge:" << mAge << endl;
		}
		~Person()
		{
			if (pName) {
				free(pName);
			}
			cout << "析构函数调用结束" << endl;
		}
	private:
		char *pName;
		int mAge;
};

void test()
{
	Person p1("mr.miaow", 31);
	// 用对象p1初始化对象p2,调用c++提供的默认拷贝构造函数
	Person p2 = p1;
}

int main()
{
	test();
	return 0;
}
