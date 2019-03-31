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
//ѡ����
class player
{
public:

	string m_name;
	int scorearr[3];

};

//��ʼ��ѡ�֣����ӵ�������
void initplayer(int len, map<int, player>&m, vector<int>&v)
{
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWSYZ";
	for (int i = 0; i < len; ++i)
	{
		player p1;
		string name="name_";
		name += arr[i];
		p1.m_name = name;
		for (int j = 0; j < 3; ++j)
		{
			p1.scorearr[j] = 0;
			
		}
		m.insert(make_pair(i + 100, p1));
		v.push_back(i + 100);
		
	}
}
//ϴ�ƣ���ǩ
void shuffle(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

void grade(int index, map<int, player>&m, vector<int>&v, vector<int>&v1)
{
	multimap<int, int, greater<int>>M;
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		num++;
		deque<int>q;
		for (int i = 0; i < 10; ++i)
		{
			q.push_back(rand() % 41 + 60);
		}
		sort(q.begin(), q.end());
		q.pop_front();
		q.pop_back();
		int total = accumulate(q.begin(), q.end(), 0);
		int average = total / q.size();

		M.insert(make_pair(average, *it));
		m[*it].scorearr[index - 1] = average;

		if (num % 6 == 0)
		{
			int cons = 0;
			for (multimap<int, int, greater<int>>::iterator pos = M.begin();pos != M.end(), cons < 3; ++pos)
			{
				//if (cons >= 3)
				//{
				//	break;
				//}
				++cons;
				v1.push_back((*pos).second);
			}
			M.clear();
		}
	}
}


void printplayer(int len, map<int, player>&m, vector<int>&v1)
{
	cout << "��" << len << "�����ɼ�" << endl;
	for (map<int, player>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "ѡ������:" << (*it).second.m_name << " �ɼ�Ϊ:" << (*it).second.scorearr[len - 1] << " ���Ϊ:" << (*it).first
			<< endl;
	}

	cout << "--------------����ѡ��--------------" << endl;
	for (vector<int>::iterator pos = v1.begin(); pos != v1.end(); ++pos)
	{
		cout << "����:"<<m[*pos].m_name <<" ���:"<<*pos<< endl;
	}

}





void test()
{
	map<int, player>m;
	vector<int>v;
	vector<int>v1;
	
	initplayer(24, m, v);
	shuffle(v);
	grade(1, m, v, v1);
	cout << v1.size() << endl;
	printplayer(1, m, v1);

}




void main()
{
	test();
	system("pause");


}