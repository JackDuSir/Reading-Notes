/*************************************************************************
	> File Name: 08-setitimer.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月04日 星期四 19时01分34秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void catch_sig(int num)
{
    printf("cat %d sig\n", num);
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, catch_sig);

    struct itimerval myit = {{3, 0}, {5, 0}}; // 第一次等待5s，之后每隔3s
    setitimer(ITIMER_REAL, &myit, NULL);

    while (1) {
        printf("who can kill me!\n");
        sleep(1);
    }
    return 0;
}

