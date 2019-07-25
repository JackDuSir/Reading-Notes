/*************************************************************************
	> File Name: pointer.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月08日 星期四 17时39分26秒
 ************************************************************************/

#include<iostream>
using namespace std;


int main()
{
	int var = 20;
	int *ip;

	ip = &var;
	
	cout << "Value of var variable: " << var << endl;

	cout << "Address stored in ip variable: " << ip << endl;

	cout << "Value of *ip variable: " << *ip << endl;

	return 0;
}
