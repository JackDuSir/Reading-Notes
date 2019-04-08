/*************************************************************************
	> File Name: 14-mutex.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 17时35分13秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;

void *thr1(void *arg)
{
    while(1) {
        // 先上锁
        pthread_mutex_lock(&mutex);
        printf("hello");
        sleep(rand()%3);
        printf("world\n");
        // 释放锁
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
}

void *thr2(void *arg)
{
    while(1) {
        // 先上锁
        pthread_mutex_lock(&mutex);
        printf("HELLO");
        sleep(rand()%3);
        printf("WORLD\n");
        // 释放锁
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
}

int main(int argc, char *argv[])
{
    pthread_t tid[2];
    pthread_create(&tid[0], NULL, thr1, NULL);
    pthread_create(&tid[1], NULL, thr2, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}

