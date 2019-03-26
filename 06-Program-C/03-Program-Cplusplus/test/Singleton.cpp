/*************************************************************************
	> File Name: Singleton.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月26日 星期二 10时24分08秒
 ************************************************************************/
/*
 * Singleton（单例）：在单例类的内部实现只生成一个实例，同时它提供一个静态的getInstance()工厂方法，让客户可以访问它的唯一实例；为了防止在外部对其实例化，将其默认构造函数和拷贝构造函数设计为私有；在单例类内部定义了一个Singleton类型的静态对象，作为外部共享的唯一实例。
 *
 *用单例模式，模拟公司员工使用打印机场景，打印机可以打印员工要输出的内容，并且可以累积打印机使用次数。
 */

#include<iostream>
using namespace std;

class Printer {
	public:
		static Printer* getInstance(){ return pPrinnter; }
		void PrintText(string text)
		{
			mTime++;
			cout << "打印内容：" << text << endl;
			cout << "已打印次数：" << mTime << endl;
			cout << "-----------------" << endl;
		}
	private:
		Printer(){ mTime = 0; }
		Printer(const Printer&){}
	private:
		static Printer *pPrinnter;
		int mTime;
};

Printer *Printer::pPrinnter = new Printer;

void test()
{
	Printer *printer = Printer::getInstance();
	printer->PrintText("离职报告！");
	printer->PrintText("入职合同！");
	printer->PrintText("提交代码！");
}

int main()
{
	test();
	return 0;
}
