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
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include<ctime>
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

void SpeakerDraw(vector<int>& v)  // & ?
{
    // 洗牌
    random_shuffle(v.begin(), v.end());
}

/*
 * 比赛
 * @param: index 第几轮
 * @param: v1 比赛选手编号
 * @param: m 选手编号和具体选手
 * @param: v2 晋级选手编号容器
 */
void SpeakerContest(int index, vector<int>& v1, map<int, Speaker>& m, vector<int>& v2)
{
    multimap<int, int, greater<int>> groupMap;  // key 分数 value 编号
    int num = 0;

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        num++;
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;   // 60 -100
            d.push_back(score);
        }
        // 排序
        sort(d.begin(), d.end());
        // 去除最高和最低
        d.pop_back();
        d.pop_front();
        // 累计分数
        int sum = accumulate(d.begin(), d.end(), 0);
        int avg = sum / d.size();
        // 将平均分放入 m 容器中
        m[*it].m_Score[index - 1] = avg;

        // 每 6 个人取前三名晋级
        // 临时容器保存 6 个人
        // 临时容器 存入数据
        groupMap.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {
            /*cout << "小组比赛成绩如下：" << endl;
            for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
            {
                cout << "编号:" << mit->second << " 姓名:" << m[mit->second].m_Name << " 得分:" << m[mit->second].m_Score[index - 1] << endl;
            }*/
            // 取前三名
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
            {
                if (count >= 3)
                    break;

                // 晋级容器 获取数据
                v2.push_back(mit->second);
                count++;
            }

            // 清空临时容器
            groupMap.clear();
        }
    }
}

void ShowScore(int index, vector<int>& v, map<int, Speaker>& m)
{
    cout << "第 " << index << " 轮比赛成绩如下：" << endl;

    for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "选手编号:" << it->first << " 姓名:" << it->second.m_Name << " 分数:" << it->second.m_Score[index - 1] << endl;
    }

    cout << "晋级选手编号:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    // 随机种子
    srand((unsigned int)time(NULL));

	vector<int> v1; // 选手编号	
	map<int, Speaker> m; //存放选手编号和选手信息
	
	// 创建选手
	CreateSpeaker(v1, m);

    // 抽签
    SpeakerDraw(v1);

    // 比赛
    vector<int> v2;     // 进入下一轮比赛的人员编号
    SpeakerContest(1, v1, m, v2);

    // 显示比赛结果
    ShowScore(1, v2, m);

    // 第二轮比赛
    SpeakerDraw(v2);
    vector<int> v3;
    SpeakerContest(2, v2, m, v3);
    ShowScore(2, v3, m);

    // 第三轮比赛
    SpeakerDraw(v3);
    vector<int> v4;
    SpeakerContest(3, v3, m, v4);
    ShowScore(2, v4, m);

	
	// 测试
//	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "编号:" << it->first << " 姓名:" << it->second.m_Name << endl;
//	}
	return 0;
}
