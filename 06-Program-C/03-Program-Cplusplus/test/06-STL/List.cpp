/*************************************************************************
	> File Name: List.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月29日 星期五 18时18分01秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> myList;
	int i = 0;
	for (i; i < 10; i++)
	{
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	i = 0;
	for (i; i < myList._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead)
			node = node->_Next;
	}
	return 0;
}

