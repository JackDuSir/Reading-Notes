#include <stdio.h>
#include <stdlib.h>

int main()
{
	//编译代码
	int flag;
	
	//在windows平台下，system成功调用，返回值为0
	flag = system("gcc hello.c -o hello");
	if(flag != 0)
	{//编译失败，中断程序
		return -1;
	}
	
	//执行到这，说明代码编译成功，开始执行程序
	//cmd /k 的作用是让终端暂停
	//system("hello");
	system("cmd /k hello");
	
	
	return 0;
}