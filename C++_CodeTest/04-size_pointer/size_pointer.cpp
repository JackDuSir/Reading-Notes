/*************************************************************************
	> File Name: size_pointer.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月08日 星期四 18时15分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX = 4;

int main()
{
	const char *name[MAX] = {
		"Zara Ali",
		"Hina Ali",
		"Nuha Ali",
		"Sara Ali"
	};


	cout << "Size name :" << sizeof(name) << endl;

	return 0;
}
