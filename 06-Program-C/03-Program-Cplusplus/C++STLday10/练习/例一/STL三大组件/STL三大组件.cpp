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
	//дvector������Ҫдvectorͷ�ļ�
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(10*i);
	}
	//����������������������һ�������������׵�ַ�ڶ���������β��ַ���������ǻص�������ӡ
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