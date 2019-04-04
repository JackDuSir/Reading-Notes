/*************************************************************************
	> File Name: 05-fork_wait.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月04日 星期四 14时59分28秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am child. will die!\n");
        sleep(2);
        return 101;
    } else if (pid > 0) {
        printf("I am parent. wait for child die!\n");
        int status;

        pid_t wpid = wait(&status);
        printf("wait ok. wpid=%d, pid=%d\n", wpid, pid);
        if (WIFEXITED(status)) {
            printf("child exit with %d\n", WEXITSTATUS(status));
        } 
        if (WIFSIGNALED(status)) {
            printf("child killed by %d\n", WTERMSIG(status));
        }

        while (1) {
            sleep(1);
        }
    }
    return 0;
}

