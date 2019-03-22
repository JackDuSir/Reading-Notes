#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>//调用适配器需要包含的头文件
using namespace std;

//函数适配器
class MyPrint :public binary_function<int, int, void >
{
public:
	void operator()(int v,int start) const
	{
		cout << "v=" << v << " start=" << start << " v+start=" << v + start << endl;
	
	}

};





void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	cout << "请输入起始值" << endl;
	int num;
	cin >> num;
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
	//bind1st是将参数绑定到第一个参数
	//bind2nd是将传入参数绑定到底第二个参数
	//成员函数适配器
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
}


//1、绑定数据 bind2nd(MyPrint(), num)
//2、继承类 binary_function<参数类型1, 参数类型2, 返回类型 >
//3、加const修饰 operator()

class GreaterThenFive :public unary_function < int, bool >
{
	bool operator()(int v)const
	{
		return v > 5;
	}
};


//取反适配器
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//查找大于5的数字
	//需求改为找小于5的数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));

}



int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}