#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>//调用系统异常
#include<string>

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






void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); ++i)
	{
		//下标访问
		//cout << s[i] << endl;
		//cout << s.at(i) << endl;
	}
	try{ cout << s.at(100) << endl; }
	//[]和at区别是[]越界会直接挂掉，at会抛出异常
	//try{ cout << s[1000] << endl; }

	//越界异常out_of_range
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

/*
string和c-style字符串转换
*/
void fun(string s)
{
	cout << s << endl;
}

void func2(const char*s)
{
	cout << s << endl;
	
}

void test03()
{
	string s = "abc";
	//把string 类型转换为 char*类型
	const char *p = s.c_str();
	//func2(s);//string 不能隐式转为char*
	fun(p);//char *隐式转换为string
}


void test08()
{
	string s = "'abcdefg";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << s << endl;
	//如果重新给s赋值它会重新开辟一个内存，&a，&b保存的不是合法的地址再给它赋值就会出错
	s = "pppppppppppppppppppppp";

	a = '1';
	b = '2';
	cout << s << endl;
}

void test04()
{
	string s = "abADSDDF9977**sd";
	for (int i = 0; i < s.size(); ++i)
	{
		//toupper函数是将小写字母转换为大写，用法是toupper(字母a)返回一个大写字母A
		//只会把小写字母转为大写字母
		//s[i] = toupper(s[i]);
		s[i] = tolower(s[i]);//j将字母转换为小写字母
	}
	cout << s << endl;

}


void test05()
{
	



}




int main()
{

	//test02();
	//test03();
	//test08();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}