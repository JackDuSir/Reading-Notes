#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

#include<Windows.h>

void callerror()
{
	MessageBoxA(0, "error", "error", 0);

}


void main()
{
	if (signal(SIGINT, callerror) == SIG_ERR)
	{
		printf("�źŴ���ʧ��");
	}
	else
	{
		raise(SIGINT);
	}
	system("pause");

	
}