#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

//创建对组
void test01()
{
	//第一种
	pair<string, int> p(string("Tom"), 100);

	//取值
	cout << "姓名：" << p.first << endl;
	cout << "年龄： " << p.second << endl;

	//第二种创建
	pair<string, int> p2 = make_pair("Jerry", 200);
	cout << "姓名：" << p2.first << endl;
	cout << "年龄： " << p2.second << endl;

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}