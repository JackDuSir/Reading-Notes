#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<numeric>

using namespace std;

/*
1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号

2) 第1轮	选手抽签 选手比赛 查看比赛结果
3) 第2轮	选手抽签 选手比赛 查看比赛结果
4) 第3轮	选手抽签 选手比赛 查看比赛结果

*/

class play
{
public:
	string m_name;
	int m_grade[3];
};


void playernumber(vector<int>&v)
{
	for (int i = 0; i < 24; ++i)
	{
		v.push_back(i + 100);
	}
}


//随机编号
void randumber(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

//保存歌手信息
void saveplaye(map<int, play> &m, vector<int> &v)
{
	char arr[] = "ABCDEFGHIJKMLNOPQRSTOVWX";
	for (int i = 0; i < 24; ++i)
	{
		string name;
		name += arr[i];
		play p1;
		p1.m_name = name;
		for (int j = 0; j < 3; ++j)
		{
			p1.m_grade[j] = 0;	
		}
		m.insert(make_pair(i + 100, p1));
		v.push_back(i + 100);
	}
}


//
void printdata(int index, map<int, play> &m, vector<int> &v, vector<int> &v2)
{
	//开辟一个容器保存它的编号和成绩，成绩是从高到低
	multimap<int, int, greater<int>> mymap;
	int num = 0;
	for (vector<int>::iterator pos = v.begin(); pos != v.end(); ++pos)
	{
		num++;
		deque<int>score;
		for (int i = 0; i < 10; ++i)
		{
			score.push_back(rand() % 41 + 60);
		}
		sort(score.begin(), score.end());
		score.pop_front();
		score.pop_back();
		int gross = accumulate(score.begin(), score.end(), 0);
		int averagea = gross / score.size();

		//保存平均成绩
		m[*pos].m_grade[index - 1] = averagea;
		//key值保存成绩，value值保存编号
		mymap.insert(make_pair(averagea, *pos));

		if (num % 6 == 0 )
		{
			int cons = 0;
			for (multimap<int, int, greater<int>>::iterator it = mymap.begin(); it != mymap.end(),cons < 3; it++, cons++)
			{
				v2.push_back(it->second);
			}
			mymap.clear();
		}
	}
}


void showscore(int index, map<int, play> &m, vector<int> &v2)
{
	cout << "第" << index << "成绩" << endl;

	for (map<int, play>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "第" << it->first << "名选手" << "姓名:" << it->second.m_name << "成绩" << it->second.m_grade[index - 1] << endl;
	}

	for (vector<int>::iterator pos = v2.begin(); pos != v2.end(); ++pos)
	{
		cout << "晋级选手:" << m[*pos].m_name << "编号:"<<(*pos)<<endl;
	}
}





int main(){


	//存储编号
	vector<int>v;
	//存储歌手
	map<int ,play>m;
	vector<int>v2;
	saveplaye(m, v);
	randumber(v);

	printdata(1, m, v, v2);
	//cout << v2.size() << endl;
	showscore(1, m, v2);

	vector<int>v3;
	printdata(2, m, v2, v3);
	//cout << v3.size() << endl;
	showscore(2, m, v3);

	vector<int>v4;
	printdata(3, m, v3, v4);
	//cout << v3.size() << endl;
	showscore(3, m, v4);


	system("pause");
	return EXIT_SUCCESS;
}