/*************************************************************************
	> File Name: 01-演讲比赛.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 六  3/30 23:04:12 2019
 ************************************************************************/
/*
比赛规则：
某市举行一场演讲比赛（ speech_contest ），共有24个人参加。比赛共三轮，前两轮为淘汰赛，第三轮为决赛。

比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛；

第一轮分为4个小组，每组6个人。比如编号为: 100-123.  整体进行抽签（draw）后顺序演讲。当小组演讲完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。

第二轮分为2个小组，每组6人。比赛完毕，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。

第三轮只剩下1组6个人，本轮为决赛，选出前三名。
	
比赛评分：10个评委打分，去除最低、最高分，求平均分每个选手演讲完由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，求得剩下的8个成绩的平均分。选手的名次按得分降序排列。
*/
/*
用STL编程，求解这个问题
1）	请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
2）	打印每一轮比赛后，小组比赛成绩和小组晋级名单
*/
/*
需求分析：
		1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号
		2) 第1轮	选手抽签 选手比赛 查看比赛结果 
		3) 第2轮	选手抽签 选手比赛 查看比赛结果
		4) 第3轮	选手抽签 选手比赛 查看比赛结果
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Speaker {
public:
		
public:
	string m_Name;	// 姓名
	int m_Score[3];	// 得分数组
};

void CreateSpeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		Speaker sp;
		sp.m_Name = "选手";
		sp.m_Name += nameSeed[i];
		for (int j = 0; j < 3; j++)
		{
			sp.m_Score[j] = 0;
		}
		v.push_back(i + 100);	// 编号 100 - 123
		m.insert(make_pair(i + 100, sp));
	}
}

int main()
{
	vector<int> v1; // 选手编号	
	map<int, Speaker> m; //存放选手编号和选手信息
	
	// 创建选手
	CreateSpeaker(v1, m);
	
	// 测试
	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号:" << it->first << " 姓名:" << it->second.m_Name << endl;
	}
	return 0;
}
