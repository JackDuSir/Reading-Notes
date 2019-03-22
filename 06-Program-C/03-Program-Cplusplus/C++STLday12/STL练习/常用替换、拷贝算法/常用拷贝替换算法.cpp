#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>
using namespace std;
/*
copy算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/

void test01()
{
	vector<int>v;
	vector<int>v1;
	 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());

	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });


}


/*
replace算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param oldvalue 新元素

replace_if算法 将容器内指定范围满足条件的元素替换为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback函数回调或者谓词(返回Bool类型的函数对象)
@param oldvalue 新元素
*/

void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), [](int a){cout << a << " "; });
	cout << endl;
	replace(v1.begin(), v1.end(), 3, 300);
	for_each(v1.begin(), v1.end(), [](int a){cout << a << " "; });
	cout << endl;

}

class compare :public binary_function<int, int, bool>
{
public:
	bool operator()(int a, int b)const
	{
		if (a > b)
		{
			return true;
		}
		return false;
	}
};

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int a){cout << a << " "; });
	cout << endl;
	replace_if(v.begin(), v.end(), bind2nd(compare(),5), 5);
	for_each(v.begin(), v.end(), [](int a){cout << a << " "; });
}


/*
swap算法 互换两个容器的元素
@param c1容器1
@param c2容器2
*/


void testt04()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int a){cout << a << ' '; });
	cout << endl;
	v1.reserve(v.size());
	swap(v, v1);
	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });
	cout << endl;
	cout << v.size() << endl;
	for_each(v.begin(), v.end(), [](int a){cout << a << ' '; });
	cout << endl;
}



int main(){


	//test01();
	//test02();
	//test03();
	testt04();
	system("pause");
	return EXIT_SUCCESS;
}