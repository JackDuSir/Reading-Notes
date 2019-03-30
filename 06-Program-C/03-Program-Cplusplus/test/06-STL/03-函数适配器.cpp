/*************************************************************************
	> File Name: 03-函数适配器.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月30日 星期六 16时13分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// 函数适配器bind1st bind2nd
// 现在我有这个需求 在遍历容器的时候，我希望将容器中的值全部加上100之后显示出来，怎么做？
// 我们直接给函数对象绑定参数 编译阶段就会报错
// for_each(v.begin(), v.end(), bind2nd(myprint(),100));
// 如果我们想使用绑定适配器,需要我们自己的函数对象继承binary_function 或者 unary_function
// 根据我们函数对象是一元函数对象 还是二元函数对象

class MyPrint : public binary_function<int, int, void> {
public:
	void operator()(int v1, int v2) const
	{
		cout << "v1=:" << v1 << " v2=:" << v2 << " v1+v2=:" << (v1 + v2) << endl;
	}
};

// 1. 函数适配器
void test01()
{
	vector<int> v;
	int i = 0;
	for (i; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始值：" << endl;
	int x;
	cin >> x;
	for_each(v.begin(), v.end(), bind1st(MyPrint (), x));
	//for_each(v.begin(), v.end(), bind2nd(MyPrint (), x));
}
// 总结：  bind1st和bind2nd区别?
// bind1st ： 将参数绑定为函数对象的第一个参数
// bind2nd ： 将参数绑定为函数对象的第二个参数
// bind1st bind2nd将二元函数对象转为一元函数对象

// 2. 取反适配器
void test02()
{
	vector<int> v;
	int i = 0;
	for (i; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(bind2nd(greater<int> (), 5)));
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	} else {
		cout << "找到了：" << *it << endl;
	}

	// 排序 二元函数对象
	sort(v.begin(), v.end(), not2(less<int> ()));
	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}
// not1 对一元函数对象取反
// not2 对二元函数对象取反

// 3. 函数指针适配器 ptr_fun
void MyPrint03(int v, int v2)
{
	cout << (v + v2) << " ";
}

void test03()
{
	vector<int> v;
	int i = 0;
	for (i; i < 10; i++)
	{
		v.push_back(i);
	}
	// ptr_fun( )把一个普通的函数指针适配成函数对象
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), 100));
}

// 4. 成员函数适配器
class Person {
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}
	// 打印函数
	void ShowPerson()
	{
		cout << "成员函数:" << "Name:" << mName << " Age:" << mAge << endl;
	}
	void Plus100()
	{
		mAge += 100;
	}
public:
	string mName;
	int mAge;
};

void MyPrint04(Person& p)
{
	cout << "姓名：" <<  p.mName << " 年龄：" << p.mAge << endl;
}

void test04()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for_each(v.begin(), v.end(), MyPrint04);
	cout << "------------------------" << endl;
	// 利用 mem_fun_ref 将Person内部成员函数适配
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
	cout << "------------------------" << endl;
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::Plus100));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
}

void test05()
{
	vector<Person*> v1;
	// 创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	for_each(v1.begin(), v1.end(), mem_fun(&Person::ShowPerson));
}
// 如果容器存放的是对象指针，  那么用 mem_fun
// 如果容器中存放的是对象实体，那么用 mem_fun_ref

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	return 0;
}
