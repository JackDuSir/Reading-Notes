#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
//#include<algorithm>
#include<algorithm>
using namespace std;
/*
vector���캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

//���� ʹ�õڶ������캯�� ���ǿ���...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector���ø�ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����

3.2.4.3 vector��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�

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
	cout << "V1����������" << endl;
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	cout << "v2����������" << endl;
	printVector(v2);

	vector<int>v4;
	v4.swap(v1);

	cout << "v1��������" << endl;
	printVector(v1);


	cout << "v4����������" << endl;
	printVector(v4);
	//Ϊ��ʱempty����true
	if (v1.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "��Ϊ��" << endl;
	}
	//
	cout << v4.capacity() << endl;
	cout << "resize" << endl;
	//��չ���ڴ��ʼ��Ϊ��
	v4.resize(10);
	v4.reserve(20);
	printVector(v4);
}





int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}