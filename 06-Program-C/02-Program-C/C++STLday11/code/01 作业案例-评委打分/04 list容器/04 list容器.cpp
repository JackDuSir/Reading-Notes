#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

//list是双向循环链表
void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for ( int i = 0; i < myList._Mysize * 2; i++){
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead){
			node = node->_Next;
		}
	}


}

//list常用API
/*
list构造函数
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
*/

void printList(list<int>&L)
{
	for (list<int>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>L(10,10);
	list<int>L2(L.begin(), L.end());

	printList(L);
	printList(L2);
	L2.push_back(100);

	//逆序打印
	for (list<int>::reverse_iterator it = L2.rbegin(); it != L2.rend();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//list迭代器不支持随机访问
	list<int>::iterator itBegin = L2.begin();
	//itBegin = itBegin + 1;


	//插入数据
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);

	printList(L3); //  200 300 100 10 30 20 

	//删除两端数据
	L3.pop_front(); //头删
	L3.pop_back(); //尾删
	printList(L3); // 300 100 10 30

	L3.insert(L3.begin(), 1000);
	printList(L3); // 1000 300 100 10 30

	//remove(elem);//删除容器中所有与elem值匹配的元素。
	L3.push_back(10);// 1000 300 100 10 30 10
	L3.remove(10); //参数 直接放值

	printList(L3);//1000 300 100  30
}


/*
list大小操作
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
*/

void test03()
{
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);

	cout << "大小：" << L3.size() << endl;
	if (L3.empty())
	{
		cout << "L3为空" << endl;
	}
	else
	{
		cout << "L3不为空" << endl;
	}

	L3.resize(10);
	printList(L3);

	L3.resize(3);
	printList(L3);

	list<int> L4;
	L4.assign(L3.begin(), L3.end());

	//200 300 100
	cout << "front: " << L4.front() << endl;
	cout << "back: " << L4.back() << endl;
}

/*
list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/

bool myCompare(int v1, int v2)
{	
	return v1 > v2; //降序
}

void test04()
{
	list<int>L;

	L.push_back(10);
	L.push_back(20);
	L.push_back(40);
	L.push_back(30);

	L.reverse();
	printList(L); // 30 40 20 10

	//所有不支持随机访问的迭代器 不可以用系统提供的算法
	// 如果不支持用系统提供算法，那么这个类内部会提供
	//sort(L.begin(), L.end()); 
	L.sort(); //从小到大

	printList(L);

	//从大到小
	L.sort(myCompare);
	printList(L);

}

//自定义数据类型
class Person
{
public:
	Person(string name, int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	//重载 == 让remove 可以删除自定义的person类型
	bool operator==( const  Person & p)
	{
		if ( this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height; //身高 
};

//Person排序规则 如果年龄 相同  按照身高的升序排序
bool myComparePerson( Person & p1,Person & p2 )
{
	//if (p1.m_Age > p2.m_Age)
	//{
	//	return true;
	//}
	//return false;

	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height < p2.m_Height;
	}
	else
	{
		return p1.m_Age > p2.m_Age;
	}
	

}

void test05()
{
	list<Person> L;

	Person p1("亚瑟", 10 , 165);
	Person p2("德玛西亚", 20 , 170);
	Person p3("火枪", 17,177);
	Person p4("德雷福斯", 19, 120);
	Person p5("MT", 18,200);
	Person p6("狗蛋", 18, 166);
	Person p7("狗剩", 18, 210);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//需求 打印数据时候 按照年龄的降序 输出
	//对于自定义数据类型 ，必须要指定排序规则
	L.sort( myComparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << " 身高："<< it->m_Height<< endl;
	}

	//删除 狗蛋 
	cout << " -------------------- " << endl;

	L.remove(p6);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << " 身高：" << it->m_Height << endl;
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