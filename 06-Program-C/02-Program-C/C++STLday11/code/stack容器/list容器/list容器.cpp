#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>

using namespace std;

/*
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。


3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
3.6.4.6 list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/

//自定义数据类
class Person
{
public:
	Person(string name, int age, int stature)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_stature = stature;
	}

	string m_name;
	int m_age;
	int m_stature;//身高
};

//排序回调函数
bool personcomper(Person &p1,Person &p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_stature < p2.m_stature;
	}
	else
	{
		return p1.m_age > p2.m_age;
	}

}

//打印数据
void printpreson(list<Person> &L)
{
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << "姓名：" <<it->m_name << " 年龄：" <<it->m_age << " 身高：" <<it->m_stature << endl;
	}
}


void test()
{
	list<Person>L;
	Person p1("马  云", 45, 160);
	Person p2("马华腾", 47, 178);
	Person p3("周宏伟", 43, 177);
	Person p4("李彦宏", 39, 185);
	Person p5("任正非", 45, 180);
	Person p6("王健林", 45, 170);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	//反转会改变容器中的数据
	L.sort(personcomper);
	cout << "-------------反转前--------------" << endl;
	printpreson(L);//打印数据

	//L.remove(p1);

	cout << "开始元素 姓名：" << L.front().m_name << " 年龄：" <<
		L.front().m_age << "身高" << L.front().m_stature << endl;
	cout << "最后元素 姓名：" << L.back().m_name << " 年龄：" <<
		L.back().m_age << "身高" << L.back().m_stature << endl;
	cout << "-------------反转后--------------" << endl;
	L.reverse();
	printpreson(L);//打印数据
	cout << "开始元素 姓名：" << L.front().m_name << " 年龄：" << 
		L.front().m_age << "身高" << L.front().m_stature << endl;
	cout << "最后元素 姓名：" << L.back().m_name << " 年龄：" <<
		L.back().m_age << "身高" << L.back().m_stature << endl;

	

}


void printint(list<int> &L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;

}



void test01()
{
	list<int>L;
	
	for (int i = 0; i < 5; ++i)
	{
		L.push_back(i);
	}
	for (int i = 0; i < 1000; ++i)
	{
		L.push_front((i * 10));
	}
	//cout << "L的大小：" << sizeof(L) << endl;
	//printint(L);
	//L.sort();
	//printint(L);
	//L.pop_front();
	//cout << "L的大小："<<sizeof(L) << endl;
	//printint(L);
	
}




int main(){


	test();
	//test01();
	system("pause");
	return EXIT_SUCCESS;
}