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
		printf("ÐÅºÅ´´½¨Ê§°Ü");
	}
	else
	{
		raise(SIGINT);
	}
	system("pause");

	
}