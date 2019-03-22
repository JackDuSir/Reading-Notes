#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;


void test()
{
	stack<int> v;
	v.push(10);
	v.push(20);
	v.push(30);
	v.push(40);

	while (v.empty()!=true)
	{
		//v.emplace();
		cout << v.top() << endl;
		
		v.pop();
		
	}

}










int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}