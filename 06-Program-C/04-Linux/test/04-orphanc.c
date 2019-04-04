/*************************************************************************
	> File Name: 04-orphanc.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月04日 星期四 14时39分19秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == 0) {
        while(1) {
            printf("I am child. pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
    } else if (pid > 0) {
        printf("I am parent. pid=%d, ppid=%d\n", getpid(), getppid());
        sleep(5);
        printf("I am parent, I will die!\n");
    }
    return 0;
}

