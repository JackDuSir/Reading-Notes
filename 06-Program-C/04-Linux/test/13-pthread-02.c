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
    int num = (int)arg;
    printf("I am a thread! pid = %d, tid = %lu\n", getpid(), pthread_self());
    return (void *)(100+num);
}

int main(int argc, char *argv[])
{
    pthread_t tid[5];
    int i = 0 ;
    for (i; i < 5; i++) {
        pthread_create(&tid[i], NULL, thr, (void *)i);
    }
    for (i = 0; i < 5; i++) {
        void *ret;
        pthread_join(tid[i], &ret); // 有序的原因
        printf("i = %d ret = %d\n", i, (int)ret);
    }
    return 0;
}

