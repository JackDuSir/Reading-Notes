/*************************************************************************
	> File Name: server.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月12日 星期五 16时54分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>

// 读回调
void read_cb(struct bufferevent *bev, void *arg)
{
    // 读缓冲区中的数据
    char buf[1024] = {0};
    bufferevent_read(bev, buf, sizeof(buf));
    printf("recv buf: %s\n", buf);

    char *pt = "你发送的数据我已经收到了...";
    bufferevent_write(bev, pt, strlen(pt)+1);
    printf("我发送了数据给客户端...\n");
}

// 写回调
void write_cb(struct bufferevent *bev, void *arg)
{
    printf("发送的数据已经被发送出去了...\n");
}

// 事件回调
void event_cb(struct bufferevent *bev, short events, void *arg)
{
    if (events & BEV_EVENT_EOF) {
        printf("connection closed\n");
    } else if (events & BEV_EVENT_ERROR) {
        printf("some other error\n");
    }

    // 释放资源
    bufferevent_free(bev);
    printf("bufferevent 资源已经被释放...\n");
}

// 连接完成之后，对应的通信操作
void listen_cb(struct evconnlistener *listener, 
               evutil_socket_t fd, 
               struct sockaddr *addr,
               int len, void *ptr)
{
    // 得到传进来的 event_base
    struct event_base *base = (struct event_base*)ptr;
    // 先接收数据 - 发送数据
    // 将 fd 封装为 bufferevent
    struct bufferevent *bev = NULL;
    bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    // 给 bufferevent 对应的读写数据缓冲区设置回调函数
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
    bufferevent_enable(bev, EV_READ);
}

int main(int argc, char *argv[])
{
    // 创建事件处理框架
    struct event_base* base = event_base_new();

    // init server info
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    // 创建监听的套接字
    // 绑定
    // 监听
    // 等待并接受链接
    struct evconnlistener* listen = NULL;
    // 有新连接的时候，listen_cb 被调用
    listen = evconnlistener_new_bind(base, listen_cb, base, 
                                     LEV_OPT_CLOSE_ON_EXEC | LEV_OPT_REUSEABLE, 
                                     -1, (struct sockaddr*)&serv, sizeof(serv));

    // 开始事件循环
    event_base_dispatch(base);

    // 释放资源
    evconnlistener_free(listen);
    event_base_free(base);

    return 0;
}

