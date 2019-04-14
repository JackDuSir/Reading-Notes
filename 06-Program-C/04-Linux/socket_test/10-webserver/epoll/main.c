/*************************************************************************
	> File Name: main.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 日  4/14 15:19:15 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("eg: %s port path\n", argv[0]);
        exit(1);
    }
    // 端口
    int port = atoi(argv[1]);

    // 修改进程的工作目录，方便后续操作
    int ret = chdir(argv[2]);
    if (ret == -1) {
        perror("chdir error");
        exit(1);
    }

    // 启动 epoll 模型
    
    return 0;
}

