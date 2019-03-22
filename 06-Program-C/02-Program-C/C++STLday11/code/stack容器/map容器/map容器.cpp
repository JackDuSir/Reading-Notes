#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

void test()
{
	
	map<int, string>m1;
	m1.insert(make_pair(1, "马  云"));
	m1.insert(make_pair(2, "任正非"));
	m1.insert(make_pair(3, "李彦宏"));
	m1.insert(make_pair(4, "马化腾"));
	m1.insert(make_pair(5, "张小虎"));


	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); ++it)
	{
		cout << "ID:" << it->first << " 姓名:" << it->second << endl;
	}

	//m1.find(3)返回一个迭代器，

	if (m1.find(7) != m1.end())
	{
		cout << "----------找到------------" << endl;
		cout << "ID:" << m1.find(3)->first << " 姓名:" << m1.find(3)->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


}
//3.8.2.6 map查找操作
//find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
//count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。


void test01()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		//打印key值
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}
	//m.erase(key
	m.erase(3);
	cout << "----------删除后-------------" << endl;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		//打印key值
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

}




int main()
{


	//test();
	test01();
	system("pause");
	return EXIT_SUCCESS;
}