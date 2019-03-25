/*************************************************************************
	> File Name: CubCompare.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 六  3/23 17:30:35 2019
 ************************************************************************/
/*
设计立方体类(Cube)，求出立方体的面积( 2*a*b + 2*a*c + 2*b*c )和体积( a * b * c)，分别用全局函数和成员函数判断两个立方体是否相等。
*/

#include<iostream>
using namespace std;

class Cub {
public:
	void setL(int l){ mL = l; }
	void setW(int w){ mW = w; }
	void setH(int h){ mH = h; }
	int getL(){ return mL; }
	int getW(){ return mW; }
	int getH(){ return mH; }
	
	// 立方体面积
	int caculateS(){ return (mL*mW + mL*mH + mW*mH) * 2; }
	
	// 立方体体积
	int caculateV(){ return mL * mW * mH; }
	
	// 成员方法
	bool CubCompare(Cub& c)
	{
		if (getL() == c.getL() && getW() == c.getW() && getH() == c.getH()){
			return true;
		}
		return false;
	}
private:
	int mL;
	int mW;
	int mH;
};

bool CubCompare(Cub& c1, Cub& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}

void test()
{
	Cub c1, c2;
	c1.setL(10);
	c1.setW(20);
	c1.setH(30);
	
	c2.setL(20);
	c2.setW(20);
	c2.setH(30);
	
	cout << "c1 面积: " << c1.caculateS() << " 体积: " << c1.caculateV() << endl;
	cout << "c2 面积: " << c2.caculateS() << " 体积: " << c2.caculateV() << endl;
	
	// 比较两个立方体是否相等
	if (CubCompare(c1, c2)) {
		cout << "c1 和 c2 相等！" << endl;
	}
	else {
		cout << "c1 和 c2 不相等！" << endl;
	}
	
	if (c1.CubCompare(c2)) {
		cout << "c1 和 c2 相等！" << endl;
	}
	else {
		cout << "c1 和 c2 不相等！" << endl;
	}
}

int main()
{
	test();
	return 0;
}
