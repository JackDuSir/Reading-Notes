#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class compare
{
public:
	bool operator()(int v1)
	{
		return v1 > 20;
	}

};


void test()
{

	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//find_if(v.begin(), v.end(), compare())第一个参数是首地址迭代器,第二个参数也是一个迭代器
	//第三参数是一个仿函数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), compare());
	cout << *pos << endl;

}

class compareclass
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void print(vector<int> &v1)
{
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << endl;
	}

}

void test01()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	sort(v1.begin(), v1.end(), compareclass());

	print(v1);

}







int main(){

	//test();
	test01();
	system("pause");
	return EXIT_SUCCESS;
}