#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
#include<deque>

using namespace std;
//评委类
class Judge
{
public:
	Judge(){};
	Judge(string name)
	{
		this->name = name;	
	}
	string name;
	
	double getgrade()
	{
		return (double)(rand() % 10+1);
	}
};


//歌手
class swan
{
public:
	swan(){};
	swan(string name)
	{
		this->name = name;
	}

	void getaverage(double average)
	{
		this->average = average;
	}

	double average;
	string name;
};

//打印评委信息
void printJudge(vector<Judge> &J)
{

	for (vector<Judge>::iterator it = J.begin(); it != J.end(); ++it)
	{
		cout << "评委姓名" << (*it).name << endl;
	}

}

//打印选手信息
void printPlayer(vector<swan> &S)
{
	for (vector<swan>::iterator it = S.begin(); it != S.end(); ++it)
	{
		cout << "姓名:" << (*it).name << endl;
		cout << "平局分:" << (*it).average << endl;
	}

}


void StatisticsGrade(vector<swan> &S, vector<Judge> &J)
{
	if ( &S == NULL || &J == NULL)
	{
		throw(0);
	}
	for (vector<swan>::iterator it = S.begin(); it != S.end(); ++it)
	{
		deque<double>V;
		double aver = 0.0;
		//获取分数到容器中
		for (vector<Judge>::iterator st = J.begin(); st != J.end(); ++st)
		{
			V.push_back((*st).getgrade());
		}
		//分数排序
		sort(V.begin(), V.end());
		V.pop_back();
		V.pop_front();
		//
		for (deque<double>::iterator av = V.begin(); av != V.end(); ++av)
		{
			aver += (*av);
		}

		aver /= V.size();
		aver += (double)90.0;
		(*it).getaverage(aver);
	}

}




void personnel(int judge, int playe)
{
	//两个容器保存选手，保存评委
	vector<Judge> J;
	vector<swan> S;
	//插入评委信息到vector容中
	for (int i = 0; i < judge; ++i)
	{
		Judge p1;
		char buf[64] = { 0 };
		sprintf(buf, "Judge_%c", 'A'+i);
		p1.name = buf;
		J.push_back(p1);
	}
	//插入选手信息到vector容器中
	for (int i = 0; i < playe; ++i)
	{
		swan p1;
		char buf[64] = { 0 };
		sprintf(buf, "Playe_%c", 'A'+ i);
		p1.name = buf;
		S.push_back(p1);
	}

	try{ StatisticsGrade(S, J); }
	catch (int)
	{
		cout << "传入容器错误!" << endl;
	}


	StatisticsGrade(S,J);//传入评委容器，传入选手容器
	printJudge(J);//打印评委信息
	printPlayer(S);//打印选手信息

}







void test()
{
	time_t ts;
	unsigned int data = (unsigned int)time(&ts);
	srand(data);
	personnel(5, 5);

}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}