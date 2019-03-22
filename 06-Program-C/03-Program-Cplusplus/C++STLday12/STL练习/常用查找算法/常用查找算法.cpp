#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include<numeric>
using namespace std;

/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/

//void test()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; ++i)
//	{
//		v.push_back(i);
//	}
//	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
//	if (pos != v.end())
//	{
//		cout << "找到" << endl;
//		cout << *pos << endl;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//}




//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
//
//
//class MyCompare :public binary_function< Person *, Person*, bool >
//{
//public:
//	bool operator()(Person *p1, Person*p2)const
//	{
//		if (p1->m_name == p2->m_name&&p1->m_age == p2->m_age)
//		{
//			return true;
//		}
//		return false;
//	}
//};
//
//
//
//void test02()
//{
//	vector<Person *>v1;
//
//	Person p1 ("aaa", 10);
//	Person p2 ("bbb", 20);
//	Person p3 ("ccc", 30);
//	Person p4 ("ddd", 40);
//	Person p5 ("eee", 50);
//
//
//	v1.push_back(&p1);
//	v1.push_back(&p2);
//	v1.push_back(&p3);
//	v1.push_back(&p4);
//	v1.push_back(&p5);
//
//	Person *p = new Person("bbb", 20);
//	//bin2nd(MyCompare(),p)把仿函数和p绑定在一起
//	vector<Person *>::iterator it = find_if(v1.begin(), v1.end(), bind2nd(MyCompare(), p));
//	if (it != v1.end())
//	{
//		cout << "找到" << endl;
//		cout << "姓名:" << (*it)->m_name << " 年龄:" << (*it)->m_age << endl;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//}

/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/

//bool compareperson(Person * v, Person * v1)
//{
//	if (v->m_age == v1->m_age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//


//void test04()
//{
//	vector<Person *>v;
//
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 20);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//
//	//adjacent_find查找重复的数据
//	vector<Person *>::iterator pos=adjacent_find(v.begin(), v.end(), compareperson);
//	cout << "姓名:" << (*pos)->m_name << "年龄:" << (*pos)->m_age << endl;
//
//	for_each(v.begin(), v.end(), [](Person *p1){cout << p1->m_name << " " << p1->m_age << endl; });
//}



/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/


//class fine
//{
//public:
//	bool operator()(Person &p1, Person &p2)
//	{
//		if (p1.m_age == p2.m_age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//





//void test05()
//{
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	//bool pos = binary_search(v.begin(), v.end(), p1, bind2nd(fine(), p1));
//	//if (pos)
//	//{
//	//	cout << "找到" << endl; 
//	//}
//
//	for_each(v.begin(), v.end(), [](Person &v){cout << v.m_name << " "<<v.m_age << endl; });
//
//
//}


/*
/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/

/*
count_if算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数

*/

struct aaaa
{
	bool operator() (int num) {
		return num == 30;
	}
};

void test06()
{
	vector<int>v;
	

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);

	//count_if()
	int i = count_if(v.begin(), v.end(),aaaa());
	cout << i << endl;

}







int main()
{

	//test();
	//test02();
	//test04();
	//test05();

	test06();
	system("pause");
	return EXIT_SUCCESS;
}