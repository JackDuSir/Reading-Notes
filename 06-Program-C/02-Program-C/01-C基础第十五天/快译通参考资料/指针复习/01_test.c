/* ************************************************************************
 *       Filename:  01_test.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2016年08月27日 11时31分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun(char *p)
{
	p = (char *)malloc( strlen("hello") + 1 );
	strcpy(p, "hello");
	//*p = '1';
	//p[0] = '1';
	*(p+0) = '1';
	printf("fun  = %s\n",  p);
}

int main(int argc, char *argv[])
{
	char *p = NULL;

	fun(p);
	printf("p = %s\n", p);

	return 0;
}


