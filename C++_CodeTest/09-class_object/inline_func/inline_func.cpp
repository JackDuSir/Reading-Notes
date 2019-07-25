/*************************************************************************
	> File Name: inline_func.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月12日 星期一 17时34分04秒
 ************************************************************************/

#include<iostream>
using namespace std;


inline int Max(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
	cout << "Max (20,10): " << Max(20, 10) << endl;
	cout << "Max (0,200): " << Max(0, 200) << endl;
	cout << "Max (100,1010): " << Max(100, 1010) << endl;
	return 0;
}
