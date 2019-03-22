#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
set_intersection算法 求两个set集合的交集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i+1);
	}
	vector<int>v3;
	v3.resize(v1.size()>v2.size() ? v2.size() : v1.size());


	vector<int>::iterator pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });

}

/*
set_union算法 求两个set集合的并集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 1);
	}
	vector<int>v3;
	v3.resize(v1.size() + v2.size());
	vector<int>::iterator pos=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });
}

/*
set_difference算法 求两个set集合的差集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 5);
	}
	vector<int>v3;
	v3.resize(v2.size() > v1.size() ? v2.size() : v1.size());
	cout << v3.size() << endl;
	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int a){cout << a << ' '; });
	cout << endl;
	vector<int>::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });

}





int main(){


	//test();
	//test01();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}