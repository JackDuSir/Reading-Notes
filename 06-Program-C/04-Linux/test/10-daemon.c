/*************************************************************************
	> File Name: 08-daemon.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 10时35分43秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

#define _FILE_NAME_FORMAT_ "%s/log/mydaemon.%ld" // 定义文件格式化

void touch_file(int num)
{
    char *HomeDir = getenv("HOME");
    char strFileName[256] = {0};
    sprintf(strFileName, _FILE_NAME_FORMAT_, HomeDir, time(NULL));

    int fd = open(strFileName, O_RDWR|O_CREAT, 0666);
    if (fd < 0) {
        perror("open err");
        exit(1);
    }
    close(fd);
}

int main(int argc, char *argv[])
{
    // 创建子进程，父进程退出
    pid_t pid = fork();
    if (pid > 0) {
        exit(1);
    }
    // 当会长
    setsid();
    // 设置掩码
    umask(0);
    // 切换目录
    chdir(getenv("HOME")); // 切换到家目录
    // 关闭文件描述符
    //close(1), close(0), close(2);
    // 执行核心伙计
    struct itimerval myit = {{60, 0}, {1, 0}};
    setitimer(ITIMER_REAL, &myit, NULL);

    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = touch_file;
    sigaction(SIGALRM, &act, NULL);

    while (1) {
        // 每隔1分钟在/home/miaopei/log 下创建文件
        sleep(60);
        // do sth
    }
    // 退出
    
    return 0;
}

