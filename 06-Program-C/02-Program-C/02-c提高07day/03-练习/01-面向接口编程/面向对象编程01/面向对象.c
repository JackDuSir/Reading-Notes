#include"port.h"

//自定义一个无返回值参数为void*的函数类型init_
typedef void(*inint_standard)(void *data);
typedef void(*import_standard)(void *data, void *buf, int len);
typedef void(*output_standard)(void *data, void *buf, int *len);
typedef void(*close_standard)(void *data);



//接收类型为init_standard类型函数
void fomwork(inint_standard init,
	import_standard import,
	output_standard output,
	close_standard close )
{
	struct data * mydata = NULL;
	init(&mydata);
	char buf[] = "hello world";
	int len = strlen(buf);
	import(mydata, buf, len);
	char mybuf[20] = { 0 };
	output(mydata, mybuf, &len);
	printf("%s\n", mybuf);
	printf("%d\n", len);

}



void test01()
{
	fomwork(init, import, output, close);

}

void main()
{

	test01();
	system("pause");
}