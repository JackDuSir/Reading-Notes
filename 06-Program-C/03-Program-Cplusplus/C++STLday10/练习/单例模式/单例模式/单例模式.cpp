#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
private:
	char c;
public:
	Base(char n) :c(n){}
	virtual ~Base(){ cout << c; }
};

class Der :public Base
{
private:
	char c;
public:
	Der(char n) :Base(n + 1), c(n){}
	~Der(){ cout << c; }
};






int main(){


	Der('X'); 
	system("pause");
	return EXIT_SUCCESS;
}
