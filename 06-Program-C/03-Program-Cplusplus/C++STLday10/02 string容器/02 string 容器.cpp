#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>
/*
string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

3.1.2.2 string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

*/

void test01()
{
	string str; //默认构造
	string str2(str); //拷贝构造
	string str3 = str;

	string str4 = "abcd";
	string str5(10, 'a');

	cout << str4 << endl;
	cout << str5 << endl;

	//基本赋值
	str = "hello";
	str2 = str4;

	//string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
	str3.assign("abcdef", 4);
	cout << str3 << endl;


	//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
	string str6;
	str6.assign(str, 1, 3); //ell ? hel 从0索引

	cout << str6 << endl;
}


/*
string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符

*/
void test02()
{
	string s = "hello world";

	for (int i = 0; i < s.size();i++)
	{
		//cout << s[i] << endl;
		cout << s.at(i) << endl;
	}
	//[] 和at区别？[]访问越界  直接挂掉 at会抛出异常

	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (out_of_range & e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "越界异常" << endl;
	}
}

/*
string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/

void test03()
{
	//拼接
	string s1 = "我";
	string s2 = "爱北京";
	s1 += s2;
	cout << s1 << endl;
	s1.append("天安门");

	cout << s1 << endl;

	//find查找

	string s = "abcdefg";
	int pos = s.find("bcf"); //找不到返回是 -1
	cout << "pos = " << pos << endl;
	
	int pos2 = s.rfind("bc"); //rfind  和find 结果一样，内部查找顺序相反
	cout << "pos2 = " << pos2 << endl; // 4 2 


	//替换
	string s3 = "hello"; //替换从pos开始n个字符为字符串str
	s3.replace(1, 3, "1111");
	cout << s3 << endl; // h1111o


}

/*
string比较操作
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。

int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/

void test04()
{
	string s1 = "abc";
	string s2 = "abcd";

	if (s1.compare(s2) == 0)
	{
		cout << "s1 等于 s2" << endl;
	}
	else if (s1.compare(s2) == 1)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}

}


/*
string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

*/

void test05()
{
	string s1 = "abcde";

	string s2 = s1.substr(1, 3);
	cout << "s2 = " << s2 << endl;

	//需求  查找一个右键的 用户名
	string email = "zhangtao@sina.com";

	int pos = email.find("@");//8 
	cout << "pos " << pos << endl;

	string usrName = email.substr(0, pos);
	cout << "用户名为：" << usrName << endl;
}


/*
string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符

*/

void test06()
{
	string s1 = "hello";
	s1.insert(1, "111");
	cout << s1 << endl; //h111ello

	//删除 111
	s1.erase(1, 3);
	cout << s1 << endl;

}


/*
string和c-style字符串转换
*/

void func(string s)
{
	cout << s << endl;
}

void func2(const char * s)
{
	cout << s << endl;
}

void test07()
{
	string s = "abc";
	//string -> const char *

	const char * p = s.c_str();

	func(p); //const char * 隐式类型转换为 string

	//const char * -> string 

	string s2(p);
	//func2(s2); //string 不能隐式类型转换为 char * 
}

void test08()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "pppppppppppppp";

	//a = '1';
	//b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

}

/*
写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
*/

void test09()
{
	string s = "abCdEfg";

	for (int i = 0; i < s.size();i++)
	{
		//s[i] = toupper(s[i]);

		//全变小写
		s[i] = tolower(s[i]);
	}

	cout << s << endl;
}

int main(){

//	test01();

	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

//	test07();

	//test08();

	test09();

	system("pause");
	return EXIT_SUCCESS;
}