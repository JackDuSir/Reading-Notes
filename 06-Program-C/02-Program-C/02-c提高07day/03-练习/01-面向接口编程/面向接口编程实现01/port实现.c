#include"port.h"





typedef void(*init_port)(void *data);//初始化数据
typedef void(*input_port)(void *data, unsigned char* buf, int effectivelength);//插入数据
typedef void(*output_port)(void *data, unsigned char* buf, int *effectivelength);//输出数据
typedef void(*colse_port)(void *data);//关闭接口



void project(init_port init,
	input_port input,
	output_port output,
	colse_port colse)
{
	struct valibdata *mydata = NULL;
	init(&mydata);
	char buf[] = "hello world!";
	input(mydata, buf, strlen(buf));
	char *temp = malloc(sizeof(strlen(buf)));
	int len = 0;
	output(mydata, temp, &len);



}


void main()
{
	project(init_norm,
		input_norm,
		output_norm,
		colse_norm);
		system("pause");

}