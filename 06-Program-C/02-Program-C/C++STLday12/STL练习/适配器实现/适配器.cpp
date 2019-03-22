#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

//1、绑定数据bind2nd
//2、继承类 binary_function<参数类型1，参数类型2，返回值类型>
//3、加const修饰 operaator()

//
//class MyPrint :public binary_function < int, int ,void >
//{
//public:
//	void operator()(int a, int b)const
//	{
//		cout << "v=" << a << " b=" << b << endl;
//	}
//};
//
//
//
//void teat01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; ++i)
//	{
//		v.push_back(i);
//	}
//	//替换结构体中的参数，如果替换第一个参数容器中的的数据传递给第二个
//	for_each(v.begin(), v.end(), bind2nd(MyPrint(), 10));
//}
//binary_function<int,int, bool>
class compare:public unary_function<int,bool>
{
public:
	bool operator()(int i)const
	{
		return i > 5;
	}
};



void test02()
{
	//一元取反
	//not1
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找大于5的数据
	//需要改为 找小于5的数字
	//vector<>                                                  //匿名对象
	vector<int>::iterator pos=find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	cout << *pos << endl;
}





void compareper(int a,int sta)
{
	cout << a + sta << endl;
};



void test03()
{
	vector < int > v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//函数适配器就是将函数指针适配为函数对象，然后把100绑定的到函数对象的参数中
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(compareper), 100));

}


void test07()
{
	mem_fun_ref()


}




int main(){


	//teat01();
	//est02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}