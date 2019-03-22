#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

/*Queue所有元素的进出都必须符合”先进先出”的条件，
只有queue的顶端元素，
才有机会被外界取用。
Queue不提供遍历功能，
也不提供迭代器。*/


void test()
{
	//没有迭代器
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	queue<int> q1;

	//while (!q.empty())
	//{
	//	cout << "队头"<<q.front() << endl;
	//	cout << "队尾" << q.back() << endl;
	//	cout << q.size() << endl;
	//	
	//	q.pop();
	//}
	q1 = q;

	while (!q1.empty())
	{
		cout << "队头" << q1.front() << endl;
		cout << "队尾" << q1.back() << endl;
		cout << q1.size() << endl;
		q1.pop();
		cout << "容器所占字节" << sizeof(q1) << endl;
	}
}




int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}