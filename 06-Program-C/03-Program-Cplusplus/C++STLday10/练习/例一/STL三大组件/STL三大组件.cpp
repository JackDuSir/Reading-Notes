#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void myPrint(int a)
{
	cout << a <<' ';

}




void test()
{
	//int arr[10];
	//写vector容器需要写vector头文件
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(10*i);
	}
	//遍历函数，三个参数，第一个参数是容器首地址第二个参数是尾地址，第三个是回调函数打印
	//for_each(v.begin(), v.end(), myPrint);


	


	for (int i = 0; i < v.size(); )
	{
		v.pop_back();
		//cout << v.size() << endl;
		for_each(v.begin(), v.end(), myPrint);
		cout << endl;
	}


}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}