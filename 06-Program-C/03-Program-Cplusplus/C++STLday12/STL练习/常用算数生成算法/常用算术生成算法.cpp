#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<numeric>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
/*
accumulate算法 计算容器元素累计总和
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 初始值，就是累加之后再加上这个值
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
	}
	cout << accumulate(v.begin(), v.end(), 0) << endl;

}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
*/

void test02()
{
	vector<int>v;
	//for (int i = 0; i < 5; ++i)
	//{
	//	v.push_back(i);
	//}
	//fill(v.begin(), v.end(), 20);
	v.resize(10);
	fill(v.begin(), v.end(), 10);
	for_each(v.begin(), v.end(), [](int a){cout << a << endl; });

}




int main(){


	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}