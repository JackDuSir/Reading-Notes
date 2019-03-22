#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
//multimap


//学生信息
class staff;
//查找信息
void seek(map<int, staff> &M, int i);
//打印信息
void myprint(map<int, staff> &m);
//输入信息
void insermes(map<int, staff> &M);
//删除信息
void deletemes(map<int, staff> &M, int ID);

//学生信息
class staff
{
public:
	staff(){};

	void setname(string name)
	{
		this->name = name;
	}
	void setage(int age)
	{
		this->age = age;
	}
	void setpone(long long pone)
	{
		this->pone = pone;	
	}
	void setwage(int wage)
	{
		this->wage = wage;
	}

	staff(string name, int age, long long pone, int wage)
	{
		this->name = name;
		this->age = age;
		this->pone = pone;
		this->wage = wage;
	}

	string name;
	int age;
	long long pone;
	int wage;
};


//打印信息
void myprint(map<int, staff> &m)
{
	for (map<int, staff>::iterator it=m.begin(); it != m.end(); ++it)
	{
		cout << "ID:" << it->first << " 姓名：" << it->second.name <<
			" 电话:" << it->second.pone << " 年龄：" << it->second.age <<
			" 工资:" << it->second.wage << endl;
	}
}



//输入信息
void insermes(map<int, staff> &M)
{
	
	int i = 1;
	int over = 1;
	cout << "结束输入请输入0" << endl;
	while (over)
	{
		//int ID;
		string name;
		long long pone;
		int wage;
		int age;
		//cout << "请输入学生编号：";
		//cin >> ID;
		//cout << endl;
		
		cout << "请输入学生姓名：";
		cin >> name;

		cout << "请输入学生年龄:";
		cin >> age;
		if (age < 0 || age>200)
		{
			continue;
		}
		
		cout << "请输入电话:";
		cin >> pone;
	
		cout << "请输入工资:";
		cin >> wage;
		cout << "你输入的是" << " 姓名:" << name << " 电话:" << pone <<
			" 年龄:" << age << " 工资:"<<wage<<endl;
		//staff(string name, int age, long long pone, int wage)
		staff p1;
		p1.setname(name);
		p1.setage(age);
		p1.setpone(pone);
		p1.setwage(wage);
		M.insert(make_pair(i, p1));
			++i;
			cin >> over;
			if (over == 0)
			{
				over = 0;
			}
			else
			{
				over = 1;
			}
	}
}

//查找信息
void seek(map<int, staff> &M,int i)
{
	if (M.find(i) != M.end())
	{
		cout << "找到" << endl;

		if (M.find(i) != M.end())
		{
			cout << "ID:" << M.find(i)->first << " 姓名:" << M.find(i)->second.name <<
				" 电话:" << M.find(i)->second.pone << " 年龄:" << M.find(i)->second.age <<
				" 工资:" << M.find(i)->second.wage<< endl;
		}		
	}
}


//删除信息
void deletemes(map<int, staff> &M,int ID)
{
	M.erase(ID);
}




void test01()
{
	map<int, staff> M;
	insermes(M);
	myprint(M);
	seek(M, 2);
	deletemes(M, 2);
	myprint(M);
}




int main(){


	//test();
	test01();
	system("pause");
	return EXIT_SUCCESS;
}