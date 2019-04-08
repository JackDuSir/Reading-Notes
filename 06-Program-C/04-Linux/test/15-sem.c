/*************************************************************************
	> File Name: 15-sem.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 18时49分57秒
 ************************************************************************/

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

sem_t blank, xfull;
#define _SEM_CNT_ 5

int queue[_SEM_CNT_]; // 模拟饼框
int beginnum = 100;

void* thr_producter(void* arg)
{
    int i = 0;
    while (1) {
        sem_wait(&blank); // 申请资源 value--
        printf("---%s---self:%lu---%d\n", __FUNCTION__, pthread_self(), beginnum);
        queue[(i++)%_SEM_CNT_] = beginnum++;
        sem_post(&xfull); // xfull++
        sleep(rand()%3);
    }
    return NULL;
}

void* thr_customer(void* arg)
{
    int i = 0;
    int num = 0;
    while (1) {
        sem_wait(&xfull);
        num = queue[(i++)%_SEM_CNT_];
        printf("---%s---self:%lu---%d\n", __FUNCTION__, pthread_self(), num);
        sem_post(&blank);
        sleep(rand()%3);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    sem_init(&blank, 0, _SEM_CNT_);
    sem_init(&xfull, 0, 0); // 消费者一开始的初始化默认没有产品

    pthread_t tid[2];

    pthread_create(&tid[0], NULL, thr_producter, NULL);
    pthread_create(&tid[1], NULL, thr_customer, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    sem_destroy(&blank);
    sem_destroy(&xfull);
    return 0;
}

