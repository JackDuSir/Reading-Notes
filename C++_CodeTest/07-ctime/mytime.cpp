/*************************************************************************
	> File Name: mytime.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月12日 星期一 10时40分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include<ctime>

int fun_seconds()
{
	time_t seconds;
	seconds = time(NULL);

	cout << "seconds: " << seconds << endl;
	
	return 0;
}

int fun_curtime()
{
	time_t curtime;

	time(&curtime);

	cout << "curtime: " << ctime(&curtime);

	return 0;
}

int fun_localtime()
{
	time_t rawtime;
	struct tm *info;
	//char buffer[80];

	time(&rawtime);

	info = localtime(&rawtime);

	cout << "localtime: " << asctime(info);

	return 0;
}

int fun_now_time()
{
	// 基于当前系统的当前日期/时间
	time_t now = time(0);

	// 把 now 转换为字符串形式
	char *dt = ctime(&now);

	cout << "本地日期和时间: " << dt << endl;

	// 把 now 转换为 tm 结构
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC 日期和时间: " << dt << endl;

	return 0;
}

int main()
{
	fun_seconds();

	fun_curtime();
	
	fun_localtime();

	fun_now_time();

	return 0;
}

