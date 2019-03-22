#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class base
{
public:
	base(){};
	base(int l, int h)
	{
		this->l = l;
		this->h = h;
	}
	virtual int area()
	{
		return 0;
	}
	int l;
	int h;
};


class trigon :public base
{
public:
	trigon(int l, int h) :base(l,h)
	{ 
		this->l = l;
		this->h = h; 
	}

	virtual int area()
	{
		return (this->l * this->h);
	}
	
};



class square :public base
{
public:
	square(int l, int h){ this->l = l; this->h = h; }
	virtual int area()
	{
		return (this->l * this->h);
	}
	
};


class roundness :public base
{
public:
	/*roundness(int r){ this->r = r; }
	virtual int area()
	{
		return int(2 * 3.14 * this->r * this->r);
	}
	int r;*/
};


void test()
{
	base * p1=new trigon(2,3);
	
	//p2.area(2, 4, 5);
	/*trigon p2(2, 3);
	p1 = &p2;*/
	cout << p1->area() << endl;

}



int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}