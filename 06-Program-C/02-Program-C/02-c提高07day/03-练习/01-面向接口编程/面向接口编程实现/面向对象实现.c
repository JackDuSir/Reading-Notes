#include "port.h"



typedef void(*init_standard)(void *data);
typedef void(*impot_standard)(void *data, void *validdata, int len);
typedef void(*out_standard)(void *data, void *outdata, int *outlen);
typedef void(*closel_standard)(void *data);


void function(
	init_standard init,
	impot_standard impot,
	out_standard out,
	closel_standard closel)
{
	struct Port * myport = NULL;
	init(&myport);

	char buf[20] = "hello world";
	int len = strlen(buf)+1;
	impot(myport, buf, len);


	char buf1[20] = { 0 };
	out(myport, buf1, &len);
	printf("%s\n", buf1);
	printf("%d", len);
	closel(myport);

}

void test01()
{
	function(init, impotrdata, dataout, close);
}

void main()
{
	test01();
	system("pause");

}