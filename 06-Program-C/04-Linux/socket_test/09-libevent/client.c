/*************************************************************************
	> File Name: clien.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 六  4/13 12:19:01 2019
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <arpa/inet.h>

void read_cb(struct bufferevent* bev, void* arg)
{
    // 接受对方发送过来的数据
    char buf[1024] = {0};
    int len = bufferevent_read(bev, buf, sizeof(buf));
    printf("recv data: %s\n", buf);

    // 给对方发送数据
    //bufferevent_write(bev, buf, len+1);
    printf("数据已经发送完成...\n");
}

void write_cb(struct bufferevent* bev, void* arg)
{
    printf("我是一个没有什么卵用的函数\n");
}

void event_cb(struct bufferevent* bev, short events, void* arg)
{
    if (events & BEV_EVENT_EOF) {
        printf("connection closed\n");
    } else if (events & BEV_EVENT_ERROR) {
        printf("some other error\n");
    } else if (events & BEV_EVENT_CONNECTED) {
        printf("已经成功连接服务器...\n");
        return ;
    }
    // 释放资源
    bufferevent_free(bev);
}

void read_terminal(int fd, short what, void* arg)
{
    // 读终端中的数据
    char buf[1024] = {0};
    int len = read(fd, buf, sizeof(buf));
    // 将数据发给server
    struct bufferevent* bev = (struct bufferevent*)arg;
    bufferevent_write(bev, buf, len+1);
}

int main(int argc, char *argv[])
{
    // server info
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);

    // 创建事件处理框架
    struct event_base* base = event_base_new();

    // 创建事件
    // 连接服务器 - fd
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // fd - bufferevent
    struct bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    // 连接服务器
    bufferevent_socket_connect(bev, (struct sockaddr*)&serv, sizeof(serv));
    
    // 给缓存区设置回调
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
    bufferevent_enable(bev, EV_READ);

    // 接受键盘输入, 将数据发送给server
    // 创建一个新事件
    struct event* ev = event_new(base, STDIN_FILENO, EV_READ | EV_PERSIST, read_terminal, bev);

    // 添加事件到event_base
    event_add(ev, NULL);

    // 启动时间循环
    event_base_dispatch(base);

    // 释放资源
    event_base_free(base);

    return 0;
}

