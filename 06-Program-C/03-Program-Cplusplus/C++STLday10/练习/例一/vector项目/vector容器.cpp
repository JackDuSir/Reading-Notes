#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
//#include<algorithm>
#include<algorithm>
using namespace std;
/*
vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。

3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/


void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout<<endl;
}



void test()
{
	
	vector<int>v;
	int arr[] = { 2, 3, 4, 1, 9 };
	vector<int>v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "V1的数据内容" << endl;
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	cout << "v2的数据内容" << endl;
	printVector(v2);

	vector<int>v4;
	v4.swap(v1);

	cout << "v1数据内容" << endl;
	printVector(v1);


	cout << "v4的数据内容" << endl;
	printVector(v4);
	//为空时empty返回true
	if (v1.empty())
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "不为空" << endl;
	}
	//
	cout << v4.capacity() << endl;
	cout << "resize" << endl;
	//扩展的内存初始化为零
	v4.resize(10);
	v4.reserve(20);
	printVector(v4);
}





int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}