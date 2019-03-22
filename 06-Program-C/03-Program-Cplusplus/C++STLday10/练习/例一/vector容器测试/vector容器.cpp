#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void test()
{

	vector<int>v;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
	}
	//数据大小
	cout<<v.size()<<endl;
	//容器大小
	cout << v.capacity() << endl;
	cout << "分配前" << endl;

	cout << "交换前" << endl;
	v.resize(3);
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	cout << "交换后" << endl;
	//有v初始化匿名容器
	vector<int>(v).swap(v);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}


void test01()
{
	vector<int>v;
	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
}


void test02()
{
	vector<int>v;
	v.reserve(100000);
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
	}
	cout << v.size() << endl;
	cout << v.empty() << endl;

	vector<int>::iterator it = v.end();
	it = it - 1;
	cout << *it << endl;
	//cout << v.end() - 1 << endl;


}




int main(){

	//test();
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}