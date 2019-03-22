#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
#define N 10
using namespace std;
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Person
{
public:
	//初始化姓名
	Person(string name)
	{
		this->name = name;
		this->score = 0;	
	}

	//获取数组
	void getscre(int *arr,int len)
	{
		this->arr = arr;
		this->arrsize = len;
	}

	//打印数组
	void print()
	{
		for (int i = 0; i < this->arrsize; ++i)
		{
			cout <<*(arr + i) << endl;
		}
	}

	//获取平均值
	void getScore(int score)
	{
		this->score = score;
	}

	//打印个人信息
	void show()
	{
		cout << "姓名:" << this->name << endl;
		cout << "平均分:" << this->score << endl;
	}

	//返回函数长度
	int retarrsize()
	{
		return this->arrsize;
	}

	//返回数组
	int *setarr()
	{
		return this->arr;
	}

private:
	int *arr;
	string name;
	int score;
	int arrsize;
};




void test()
{
	vector<Person *>v;


	Person p1("A");
	Person p2("B");
	Person p3("C");
	Person p4("D");
	Person p5("E");

	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	int arr1[N] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		arr1[i] = rand() % 100 + 1;
	}


	//排序,去除最大的最小的

	p1.getscre(arr1,N);
	p2.getscre(arr1,N);
	p3.getscre(arr1,N);
	p4.getscre(arr1,N);
	p5.getscre(arr1,N);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	p1.print();
	cout << "------------------------" << endl;

	for (vector<Person *>::iterator it = v.begin(); it != v.end(); ++it)
	{
		int ave = 0;
		deque<int>v1;
		for (int i = 0; i < (*it)->retarrsize(); ++i)
		{
			v1.push_back((*it)->setarr()[i]);
		}
		//排序
		sort(v1.begin(), v1.end());
		v1.pop_front();
		v1.pop_back();

		//求平均数
		for (deque<int>::iterator tt = v1.begin(); tt != v1.end(); ++tt)
		{
			ave += (*tt);
		}
		ave /= v1.size();

		//把平均值传回去
		(*it)->getScore(ave);
	}


	p1.show();
	p2.show();
	p3.show();
	p4.show();
	p5.show();

}




int main(){


	test();
	//string::npos;
	system("pause");
	return EXIT_SUCCESS;
}