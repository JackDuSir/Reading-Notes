#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>//����ϵͳ�쳣
#include<string>

/*
string ���캯��
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��

3.1.2.2 string������ֵ����
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
*/






void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); ++i)
	{
		//�±����
		//cout << s[i] << endl;
		//cout << s.at(i) << endl;
	}
	try{ cout << s.at(100) << endl; }
	//[]��at������[]Խ���ֱ�ӹҵ���at���׳��쳣
	//try{ cout << s[1000] << endl; }

	//Խ���쳣out_of_range
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

/*
string��c-style�ַ���ת��
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
	//��string ����ת��Ϊ char*����
	const char *p = s.c_str();
	//func2(s);//string ������ʽתΪchar*
	fun(p);//char *��ʽת��Ϊstring
}


void test08()
{
	string s = "'abcdefg";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << s << endl;
	//������¸�s��ֵ�������¿���һ���ڴ棬&a��&b����Ĳ��ǺϷ��ĵ�ַ�ٸ�����ֵ�ͻ����
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
		//toupper�����ǽ�Сд��ĸת��Ϊ��д���÷���toupper(��ĸa)����һ����д��ĸA
		//ֻ���Сд��ĸתΪ��д��ĸ
		//s[i] = toupper(s[i]);
		s[i] = tolower(s[i]);//j����ĸת��ΪСд��ĸ
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