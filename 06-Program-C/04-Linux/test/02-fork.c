/*************************************************************************
	> File Name: 02-fork.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月03日 星期三 20时41分41秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Begin ...\n");
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork orr");
        exit(1);
    }
    if (pid == 0) {
        // 子进程
        printf("I am a child, pid=%d, ppid=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        // 父进程的逻辑
        printf("childpid = %d, self=%d, ppid=%d\n", pid, getpid(), getppid());
    }
    printf("End ...\n");
    return 0;
}

