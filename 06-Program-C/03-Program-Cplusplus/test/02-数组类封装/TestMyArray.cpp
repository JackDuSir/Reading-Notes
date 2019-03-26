/*************************************************************************
	> File Name: TestMyArray.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月26日 星期二 16时05分48秒
 ************************************************************************/

#include<iostream>
#include"MyArray.h"
using namespace std;

void test()
{
	// 创建数组
	MyArray myarray(50);

	// 数组中插入元素
	int i = 0;
	for (i; i < 50; i++)
	{
		// 尾插法
		myarray.PushBack(i);
		//myarray.SetData(i);
	}

	// 打印数组中元素
	for (i = 0; i < myarray.GetLength(); i++)
	{
		cout << myarray.GetData(i) << " ";
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}
