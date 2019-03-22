#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<ctime>
#include<string>
using namespace std;


//multimap 案例
//公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
class staff
{
public:
	staff(string name, int age, long long pone, int wage) : m_name(name), m_age(age), m_pone(pone), m_wage(wage)
	{}

	string m_name;
	int m_age;
	long long m_pone;
	int m_wage;

};
//插入数据
void inser(multimap<int, staff>&M,int max)
{
	for (int i = 0; i < max; ++i)
	{
		int m_i = rand() % 10;
		char name[64] = {0};
		long long pone = 0;
		int wage = 0;
		int age = 0;
		sprintf(name, "name_%d", (rand() % 10));
		string m_name = name;
		pone = (rand() % 10 + 15556930460);
		wage = (rand() % 10 + 1) * 1000;
		age = rand() % 10 + 30;
		staff p1(m_name, age, pone, wage);
		M.insert(make_pair((rand() % 4), p1));
	}
}


//打印
void print(staff & s)
{
	cout << "姓名:" << s.m_name 
		<< "年龄:" << s.m_age 
		<< "电话:" << s.m_pone 
		<< "工资:" <<s.m_wage<< endl;
}

//遍历打印
void printmultimap(multimap<int, staff> &M)
{
	for (multimap<int, staff>::iterator it = M.begin(); it != M.end(); ++it)
	{
		cout << "姓名" << it->second.m_name << " 年龄:" << it->second.m_age << " 电话:" << it->second.m_pone
			<< " 薪水:" << it->second.m_wage <<" 部门:"<<it->first<< endl;
	}
}




void test()
{
	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	multimap<int, staff>M;
	inser(M, 5);
	cout << "全部员工信息" << endl;
	printmultimap(M);
	//for (multimap<int, staff>::iterator it = M.begin(); it != M.end(); ++it)
	//{
	//	
	//
	//}
	
	//M.find(3);
	if (M.find(3) != M.end())
	{
		cout << "-------------------找到------------------" << endl;
		cout << "姓名" << M.find(3)->second.m_name << " 年龄:" << M.find(3)->second.m_age << " 电话:" << M.find(3)->second.m_pone
			<< " 薪水:" << M.find(3)->second.m_wage << " 部门:" << M.find(3)->first << endl;
	}
	else
	{
		cout << "-------------------未找到------------------" << endl;
	}
}



int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}