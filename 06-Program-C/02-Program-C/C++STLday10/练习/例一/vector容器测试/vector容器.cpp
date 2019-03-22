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
	//���ݴ�С
	cout<<v.size()<<endl;
	//������С
	cout << v.capacity() << endl;
	cout << "����ǰ" << endl;

	cout << "����ǰ" << endl;
	v.resize(3);
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	cout << "������" << endl;
	//��v��ʼ����������
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