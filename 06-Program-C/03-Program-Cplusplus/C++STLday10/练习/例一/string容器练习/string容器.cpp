#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//
//string();//创建一个空的字符串 例如: string str;      
//string(const string& str);//使用一个string对象初始化另一个string对象
//string(const char* s);//使用字符串s初始化
//string(int n, char c);//使用n个字符c初始化 
//
//3.1.2.2 string基本赋值操作
//string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
//string& operator=(const string &s);//把字符串s赋给当前的字符串
//string& operator=(char c);//字符赋值给当前的字符串
//string& assign(const char *s);//把字符串s赋给当前的字符串
//string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
//string& assign(const string &s);//把字符串s赋给当前字符串
//string& assign(int n, char c);//用n个字符c赋给当前字符串
//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串


void test()
{
	string str = "hafhakfhkak";
	char *mystr = "hhhh";
	str = mystr;

	//str.assign(10, 'a');
	str.assign(mystr);
	cout << str << endl;

}


//string& operator+=(const string& str);//重载+=操作符
//string& operator+=(const char* str);//重载+=操作符
//string& operator+=(const char c);//重载+=操作符
//string& append(const char *s);//把字符串s连接到当前字符串结尾
//string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string &s);//同operator+=()
//string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
//string& append(int n, char c);//在当前字符串结尾添加n个字符c







void test01()
{
	string name = "尼姑拉丝·";
	string youname = "露西";
	name += youname;
	char * ch = "威尔史密斯";
	//youname.append(ch);
	//youname.append(10, 'a');
	
	youname.append(name, 4, 10);


	cout << youname << endl;
}

//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s



void test02()
{
	//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找

	string arr = "abcde";
	string brr = "bc";
	
	cout << arr.find(brr,3) << endl;
	//string::npos是42949674295
	//如果找不到返回nops
	cout << string::npos << endl;

}

/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
*/
class Person
{
	//const
	//int compare(const string &s)const在后面添加const修饰的是this指针
	int compare(const string &s) const//与字符串s比较,this
	{
		end(j) - begin(i)

	}

};




void test02()
{
	
	//int compare(const char *s) const;//与字符串s比较


}






int main()
{
	//test();
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}