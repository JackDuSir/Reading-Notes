/*************************************************************************
	> File Name: epoll_server.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 日  4/14 15:23:12 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include "epoll_server.h"

#define MAXSIZE 2000

void epoll_run(int port)
{
    // 创建一个 epoll 树的根节点
    int epfd = epoll_create(MAXSIZE);
    if (cpfd == -1) {
        perror("epoll_create error");
        exit(1);
    }

    // 添加要监听的节点
    // 先添加监听 lfd
    int lfd = init_listen_fd(port, epfd);
    
    // 委托内核检测添加到树上的节点
    struct epoll_event all[MAXSIZE];
    while (1) {
        int ret = epoll_wait(epfd, all, MAXSIZE, -1);
        if (ret == -1) {
            perror("epoll_wait error");
            exit(1);
        }

        // 遍历发生变化的节点
        for (int i = 0; i < ret; ++i) {
            // 只处理读事件，其他事件默认不处理
            struct epoll_event *pev = &all[i];
            if (!(pev->events & EPOLLIN)) {
                // 不是读事件
                continue;
            }
            if (pev->data.fd == lfd) {
                // 接受连接请求
            } else {
                // 读数据
            }
        }
    }
}

int init_listen_fd(int port, int epfd)
{
    // 创建监听套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        perror("socket error");
        exit(1);
    }

    // lfd绑定本地 IP 和 port
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INTE;
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // 端口复用
    int flag = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

    int ret = bind(lfd, (struct sockaddr*)&serv, sizeof(serv));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    // 设置监听
    ret = listen(lfd, 64);
    if (ret == -1) {
        perror("listen error");
        exit(1);
    }

    // lfd 添加到 epoll 树上
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = lfd;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    if (ret == -1) {
        perror("epoll_ctl error");
        exit(1);
    }
    return lfd;
}

