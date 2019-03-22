#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;


void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()����������
	}
}

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

void printVector( vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector <int >v;
	int arr[] = { 2, 3, 4, 1, 9 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int>v2(v1.begin(), v1.end());

	printVector(v2);

	vector<int>v3(10, 100);

	printVector(v3);

	//��ֵʹ��
	vector<int>v4;
	v4.assign(v3.begin(), v3.end());
	printVector(v4);


	v4.swap(v2);

	cout << "�������v4 " << endl;
	printVector(v4);

	cout << "v4�����Ĵ�С" << v4.size() << endl;

	if (v4.empty())
	{
		cout << "v4��" << endl;
	}
	else
	{
		cout << "v4����" << endl;
	}
	
	//v4 23419
	v4.resize(10,-1); //�ڶ���������Ĭ��ֵ ��Ĭ��0 
	printVector(v4);

	v4.resize(3);
	printVector(v4);

}


int main(){
//	test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}