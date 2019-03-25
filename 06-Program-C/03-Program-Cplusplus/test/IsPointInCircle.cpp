/*************************************************************************
	> File Name: IsPointInCircle.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 六  3/23 18:07:35 2019
 ************************************************************************/
/*
设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。
假如圆心坐标为x0, y0, 半径为r，点的坐标为x1, y1：
1）点在圆上：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) == r*r
2）点在圆内：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) < r*r
3）点在圆外：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) > r*r
*/

#include<iostream>
using namespace std;

class Point {
public:
	void setX(int x){ mX = x; }
	void setY(int y){ mY = y; }
	int getX(){ return mX; }
	int getY(){ return mY; }
private:
	int mX;
	int mY;
};

class Circle {
public:
	void setP(int x, int y)
	{
		mP.setX(x);
		mP.setY(y);
	}
	void setR(int r){ mR = r; }
	Point& getP(){ return mP; }
	int getR(){ return mR; }
	
	// 判断点和圆的关系
	void IsPointInCircle(Point& point)
	{
		int distance = (point.getX() - mP.getX()) * (point.getX() - mP.getX()) + (point.getY() - mP.getY()) * (point.getY() - mP.getY());
		int radius = mR * mR;
		if (distance < radius) {
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆内！" << endl;
		}
		else if (distance > radius) {
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆外！" << endl;
		}
		else {
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆上！" << endl;
		}
	}
private:
	Point mP;	// 圆心
	int mR;		// 半径
};

void test()
{
	Circle circle;
	circle.setP(20, 20);
	circle.setR(5);
	
	Point point;
	point.setX(25);
	point.setY(20);
	
	circle.IsPointInCircle(point);
}

int main()
{
	test();
	return 0;
}
