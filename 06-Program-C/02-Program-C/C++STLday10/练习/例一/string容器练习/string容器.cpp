#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//
//string();//����һ���յ��ַ��� ����: string str;      
//string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
//string(const char* s);//ʹ���ַ���s��ʼ��
//string(int n, char c);//ʹ��n���ַ�c��ʼ�� 
//
//3.1.2.2 string������ֵ����
//string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
//string& operator=(const string &s);//���ַ���s������ǰ���ַ���
//string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
//string& assign(const char *s);//���ַ���s������ǰ���ַ���
//string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
//string& assign(const string &s);//���ַ���s������ǰ�ַ���
//string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
//string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���


void test()
{
	string str = "hafhakfhkak";
	char *mystr = "hhhh";
	str = mystr;

	//str.assign(10, 'a');
	str.assign(mystr);
	cout << str << endl;

}


//string& operator+=(const string& str);//����+=������
//string& operator+=(const char* str);//����+=������
//string& operator+=(const char c);//����+=������
//string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
//string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//string& append(const string &s);//ͬoperator+=()
//string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
//string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c







void test01()
{
	string name = "�����˿��";
	string youname = "¶��";
	name += youname;
	char * ch = "����ʷ��˹";
	//youname.append(ch);
	//youname.append(10, 'a');
	
	youname.append(name, 4, 10);


	cout << youname << endl;
}

//int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
//int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
//int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
//int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
//int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
//int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
//int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
//int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
//string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s



void test02()
{
	//int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����

	string arr = "abcde";
	string brr = "bc";
	
	cout << arr.find(brr,3) << endl;
	//string::npos��42949674295
	//����Ҳ�������nops
	cout << string::npos << endl;

}

/*
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��
*/
class Person
{
	//const
	//int compare(const string &s)const�ں������const���ε���thisָ��
	int compare(const string &s) const//���ַ���s�Ƚ�,this
	{
		end(j) - begin(i)

	}

};




void test02()
{
	
	//int compare(const char *s) const;//���ַ���s�Ƚ�


}






int main()
{
	//test();
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}