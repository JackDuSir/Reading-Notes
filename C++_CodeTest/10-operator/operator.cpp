/*************************************************************************
	> File Name: operator.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月13日 星期二 11时24分46秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Distance
{
	private:
		int feet;
		int inches;
	public:
		// 构造函数
		Distance()
		{
			feet = 0;
			inches = 0;
		}
		Distance(int f, int i)
		{
			feet = f;
			inches =i;
		}
		// 显示距离的方法
		void displayDistance()
		{
			cout << "F: " << feet << " I: " << inches << endl;
		}
		// 重载负运算符（ - ）
		Distance operator - ()
		{
			feet = -feet;
			inches = -inches;
			return Distance(feet, inches);
		}
		// 重载小于运算符（ < ）
		bool operator < (const Distance& d)
		{
			if(feet < d.feet)
			{
				return true;
			}
			if(feet == d.feet && inches < d.inches)
			{
				return true;
			}
			return false;
		}

};

int main()
{
	Distance D1(11, 10), D2(-5, 11);

	-D1;
	D1.displayDistance();

	-D2;
	D2.displayDistance();

	Distance D3(11, 10), D4(5, 11);
	if(D3 < D4)
	{
		cout << "D3 is less than D4" << endl;
	}
	else
	{
		cout << "D4 is less than D3" << endl;
	}

	return 0;
}

