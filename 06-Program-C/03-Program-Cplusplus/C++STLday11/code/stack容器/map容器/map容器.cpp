#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

void test()
{
	
	map<int, string>m1;
	m1.insert(make_pair(1, "��  ��"));
	m1.insert(make_pair(2, "������"));
	m1.insert(make_pair(3, "�����"));
	m1.insert(make_pair(4, "����"));
	m1.insert(make_pair(5, "��С��"));


	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); ++it)
	{
		cout << "ID:" << it->first << " ����:" << it->second << endl;
	}

	//m1.find(3)����һ����������

	if (m1.find(7) != m1.end())
	{
		cout << "----------�ҵ�------------" << endl;
		cout << "ID:" << m1.find(3)->first << " ����:" << m1.find(3)->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


}
//3.8.2.6 map���Ҳ���
//find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
//count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������


void test01()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		//��ӡkeyֵ
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}
	//m.erase(key
	m.erase(3);
	cout << "----------ɾ����-------------" << endl;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		//��ӡkeyֵ
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

}




int main()
{


	//test();
	test01();
	system("pause");
	return EXIT_SUCCESS;
}