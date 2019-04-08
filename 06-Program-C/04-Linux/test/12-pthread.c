/*************************************************************************
	> File Name: 12-pthread.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 12时50分48秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thr(void *arg)
{
    printf("I am a thread! pid = %d, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, thr, NULL);
    printf("I am main trhead. pid = %d, tid = %lu\n", getpid(), pthread_self());
    sleep(1);
    return 0;
}

