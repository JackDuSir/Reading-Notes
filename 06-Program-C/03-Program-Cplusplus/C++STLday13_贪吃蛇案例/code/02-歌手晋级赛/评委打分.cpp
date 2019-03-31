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
1) ����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWX �� �������÷֣�ѡ�ֱ��

2) ��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
3) ��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
4) ��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������

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


//������
void randumber(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

//���������Ϣ
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
	//����һ�������������ı�źͳɼ����ɼ��ǴӸߵ���
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

		//����ƽ���ɼ�
		m[*pos].m_grade[index - 1] = averagea;
		//keyֵ����ɼ���valueֵ������
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
	cout << "��" << index << "�ɼ�" << endl;

	for (map<int, play>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "��" << it->first << "��ѡ��" << "����:" << it->second.m_name << "�ɼ�" << it->second.m_grade[index - 1] << endl;
	}

	for (vector<int>::iterator pos = v2.begin(); pos != v2.end(); ++pos)
	{
		cout << "����ѡ��:" << m[*pos].m_name << "���:"<<(*pos)<<endl;
	}
}





int main(){


	//�洢���
	vector<int>v;
	//�洢����
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