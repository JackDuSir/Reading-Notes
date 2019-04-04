/*************************************************************************
	> File Name: 09-sigaction.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月04日 星期四 19时22分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void catch_sig(int num)
{
    printf("catch %d sig\n");
}

int main(int argc, char *argv[])
{
    // 注册一下捕捉函数
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = catch_sig;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);

    // setitimer
    struct itimerval myit = {{3, 0}, {5, 0}};
    setitimer(ITIMER_REAL, &myit, NULL);
    while (1) {
        printf("who can kill me!\n");
        sleep(1);
    }

    return 0;
}

