#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//set  multiset头文件
#include <set>
#include <string>

/*
set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

*/

void printSet( set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	//关联式容器 key进行排序，从小到大
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	printSet(s1);

	if (s1.empty())
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "size = " << s1.size() << endl;
	}

	s1.erase(s1.begin()); // 3 5 7 9
	printSet(s1);
	s1.erase(3); //  5 7 9
	printSet(s1);
}

/*
set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/

void test02()
{
	set<int>s1;
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	//对于set 没有value  key就是value

	set<int>::iterator pos = s1.find(2);
	//判断是否找到
	if (pos != s1.end())
	{
		cout << "找到了：值为：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//count(key);//查找键key的元素个数 set而言 结果 0或者1 

	int num =  s1.count(2);
	cout <<  "2的个数为： " << num << endl;


	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	set<int>::iterator it =  s1.lower_bound(3); // 10就是未找到
	if (it!= s1.end())
	{
		cout << "找到了 lower_bound (3)的值为：" << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	// upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	set<int>::iterator it2 = s1.upper_bound(3);
	if (it2 != s1.end())
	{
		cout << "找到了 upper_bound (3)的值为：" << *it2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	//上下限 就是lower_bound   upper_bound
	pair<set<int>::iterator, set<int>::iterator>  ret =  s1.equal_range(3);
	//获取第一个值

	if (ret.first != s1.end())
	{
		cout << "找到equal_range中 lower_bound 的值 ：" << *(ret.first) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//获取第二个值
	if (ret.second != s1.end())
	{
		cout << "找到equal_range中 upper_bound 的值 ：" << *(ret.second) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	
}


//set容器 不允许插入重复的键值
void test03()
{
	set<int> s1;
	pair<set<int>::iterator,bool> ret =  s1.insert(10);

	if (ret.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}

	printSet(s1);
	

	//multiset允许插入重复值
	multiset<int> mul;
	mul.insert(10);
	mul.insert(10);

}

//指定set排序规则 从大到小
//仿函数
class myCompare
{
public:
	//重载 ()
	bool operator()( int v1 ,int v2)
	{
		return v1 > v2;
	}
};


//set容器排序
void test04()
{
	set<int,myCompare>s1;
	
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);

	//printSet(s1);

	//从大到小排序
	//在插入之前就指定排序规则

	for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class myComparePerson
{
public:
	bool operator()( const Person & p1, const Person & p2)
	{
		if (p1.m_Age > p2.m_Age) //降序
		{
			return true;
		}
		return false;
	}

};

void test05()
{
	set<Person, myComparePerson> s1;

	Person p1("大娃", 100);
	Person p2("二娃", 90);
	Person p3("六娃", 10);
	Person p4("爷爷", 1000);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	//插入自定义数据类型，上来就指定好排序规则

	//显示
	for (set<Person, myComparePerson>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}

}

int main(){

	//test01();

	//test02();

	//test03();

	//test04();

	test05();

	system("pause");
	return EXIT_SUCCESS;
}