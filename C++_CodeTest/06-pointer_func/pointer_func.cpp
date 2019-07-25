/*************************************************************************
	> File Name: pointer_func.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月09日 星期五 17时07分20秒
 ************************************************************************/

#include<iostream>
using namespace std;


void getSeconds(unsigned long *par);

int main()
{
	unsigned long sec;

	getSeconds(&sec);

	cout << "Number of seconds: " << sec << endl;

	return 0;
}

void getSeconds(unsigned long *par)
{
	*par = time(NULL);
	return ;
}
