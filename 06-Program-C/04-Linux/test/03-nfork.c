/*************************************************************************
	> File Name: 03-nfork.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月04日 星期四 12时34分43秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 5;
    int i = 0;
    pid_t pid = 0;
    for (i; i < n; i ++) {
        pid = fork();
        if (pid == 0) {
            printf("I am child, pid=%d, ppid=%d\n", getpid(), getppid());
            break; // 子进程退出循环的接口
        } else if (pid > 0) {
            printf("I am father, pid=%d, ppid=%d\n", getpid(), getppid());
        }
    }

    sleep(i);
    if (i < 5) {
        printf("I am child, will exit. pid=%d, ppid=%d\n", getpid(), getppid());
    } else {
        printf("I am parent, will exit. pid=%d, ppid=%d\n", getpid(), getppid());
    }
    return 0;
}

