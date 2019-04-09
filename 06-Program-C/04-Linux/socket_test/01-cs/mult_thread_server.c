/*************************************************************************
	> File Name: mult_thread_server.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月09日 星期二 20时07分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

// 自定义数据结构
typedef struct sockinfo {
    int fd;
    struct sockaddr_in addr;
    pthread_t id;
} SockInfo;

// 子线程处理函数
void* worker(void* arg)
{
    char ip[64];
    char buf[1024];
    SockInfo* info = (SockInfo *)arg;
    // 通信
    while (1) {
        printf("client IP: %s, Port: %d\n",
               inet_ntop(AF_INET, &info->addr.sin_addr.s_addr, ip, sizeof(ip)),
               ntohs(info->addr.sin_port));
        char buf[1024];
        int len = read(info->fd, buf, sizeof(buf));
        if (len == -1) {
            perror("read error");
            exit(1);
        } else if (len == 0) {
            printf("客户端断开了连接\n");
            close(info->fd);
            break;
        } else {
            printf("recv buf: %s\n",buf);
            write(info->fd, buf, len);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("eg: %s port\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in serv_addr;
    socklen_t serv_len = sizeof(serv_addr);
    int port = atoi(argv[1]);

    // 创建套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd < 0) {
        perror("socket error");
        exit(1);
    }

    // 初始化服务器 sockaddr_in
    memset(&serv_addr, 0 , serv_len);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    // 绑定 ip 和端口
    bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

    // 设置同时监听的最大个数
    listen(lfd, 36);
    printf("Start accept ......\n");

    int i = 0;
    SockInfo info[256];
    // 规定 fd == -1
    for (i = 0; i < sizeof(info)/sizeof(info[0]); ++i) {
        info[i].fd = -1;
    }

    socklen_t cli_len = sizeof(struct sockaddr_in);
    while (1) {
        // 选一个没有被使用的，最小的数组元素
        for (i = 0; i < 256; ++i) {
            if (info[i].fd == -1) {
                break;
            }
        }
        if (i == 256) {
            break;
        }

        // 主线程 - 等待接受链接请求
        info[i].fd = accept(lfd, (struct sockaddr*)&info[i].addr, &cli_len);
        
        // 创建子线程 - 通信
        pthread_create(&info[i].id, NULL, worker, &info[i]);

        // 设置线程分离
        pthread_detach(info[i].id);
    }
    close(lfd);

    // 只退出主线程
    pthread_exit(NULL);

    return 0;
}

