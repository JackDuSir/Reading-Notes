#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

/*Queue����Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������
ֻ��queue�Ķ���Ԫ�أ�
���л��ᱻ���ȡ�á�
Queue���ṩ�������ܣ�
Ҳ���ṩ��������*/


void test()
{
	//û�е�����
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	queue<int> q1;

	//while (!q.empty())
	//{
	//	cout << "��ͷ"<<q.front() << endl;
	//	cout << "��β" << q.back() << endl;
	//	cout << q.size() << endl;
	//	
	//	q.pop();
	//}
	q1 = q;

	while (!q1.empty())
	{
		cout << "��ͷ" << q1.front() << endl;
		cout << "��β" << q1.back() << endl;
		cout << q1.size() << endl;
		q1.pop();
		cout << "������ռ�ֽ�" << sizeof(q1) << endl;
	}
}




int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}