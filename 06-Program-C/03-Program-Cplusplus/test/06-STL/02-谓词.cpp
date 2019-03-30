/*************************************************************************
	> File Name: 02-谓词.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月30日 星期六 15时19分03秒
 ************************************************************************/
/*
 * 谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。
 *
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GreaterThenFive {
public:
	bool operator()(int num)
	{
		return num > 5;
	}
};

//  一元谓词
void test01()
{
	vector<int> v;
	int i = 0;
	for (i; i < 10; i ++)
		v.push_back(i);

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThenFive());
	if (it == v.end())
	{
		cout << "没有找到" << endl; 
	} else {
		cout << "找到了：" << *it << endl;
	}
}

// 二元谓词

int main()
{
	test01();
	return 0;
}
