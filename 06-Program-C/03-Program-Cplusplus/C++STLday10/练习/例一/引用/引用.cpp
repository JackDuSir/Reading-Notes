#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class  Person
{
public:

	Person(int a)
	{
		this->a = a;

	}
	~Person()
	{
		cout << "Îö¹¹µ÷ÓÃ" << endl;
	}
	int ret()
	{
		return a;
	}
	int a;
};
void  test()
{

	Person p1(10);
	int &a = p1.ret();
	

	
}







int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}