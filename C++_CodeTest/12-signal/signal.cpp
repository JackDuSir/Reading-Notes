/*************************************************************************
	> File Name: signal.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月14日 星期三 10时54分39秒
 ************************************************************************/

#include<iostream>
using namespace std;


#include<csignal>
#include<cstdlib>
#include<unistd.h>

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";

	// 清理并关闭
	// 终止程序
	
	exit(signum);

}

int main()
{
	int i = 0;

	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandler);

	while(++i) {
		cout << "Going to sleep ..." << endl;
		if(i == 3) {
			raise(SIGINT);
		}
		sleep(1);
	}

	return 0;
}

