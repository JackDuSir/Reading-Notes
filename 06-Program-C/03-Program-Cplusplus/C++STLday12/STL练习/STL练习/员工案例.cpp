#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;
enum{ RENLI, MEISHU, JISHU };
//员工类
class worlk
{
public:

	string m_name;
	int m_money;
};

//插入如
void insert(vector<worlk> &v, multimap<int, worlk> &m)
{
	for (vector<worlk>::iterator it = v.begin(); it != v.end(); ++it)
	{
		m.insert(make_pair(rand() % 3, *it));
	}
}

//打印
void print(multimap<int, worlk> &m)
{
	for (multimap<int, worlk>::iterator it = m.begin(); it != m.end(); it++)
	{

		cout << "姓名:" << it->second.m_name << " 工资:" << it->second.m_money << endl;
	}
}

//分部门显示
void printfwordk(multimap<int, worlk> &m)
{
	
	multimap<int, worlk>::iterator it = m.find(RENLI);
	int pos=m.count(RENLI);
	int size = 0;
	cout << "人力部" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "姓名:" << (*it).second.m_name << " 工资:" << (*it).second.m_money << endl;
	}
	pos = m.count(MEISHU);
	size = 0;
	cout << "美术部" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "姓名:" << (*it).second.m_name << " 工资:" << (*it).second.m_money << endl;
	}
	pos = m.count(JISHU);
	size = 0;
	cout << "技术部" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "姓名:" << (*it).second.m_name << " 工资:" << (*it).second.m_money << endl;
	}
}




void test()
{
	vector<worlk> v;
	multimap<int, worlk> m;
	string str = "ABCDE";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		worlk p1;
		string name = "员工";
		name += str[i];
		p1.m_name = name;
		p1.m_money = rand() % 10000 + 10000;
		v.push_back(p1);
	}
	insert(v, m);
	print(m);
	printfwordk(m);
	
}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}