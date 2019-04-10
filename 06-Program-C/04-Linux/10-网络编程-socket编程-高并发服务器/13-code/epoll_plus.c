#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/epoll.h>

typedef struct sockinfo
{
    int fd;
    struct sockaddr_in sock;
}SockInfo;

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        printf("./a.out port\n");
        exit(1);
    }
    int lfd, cfd;
    struct sockaddr_in serv_addr, clien_addr;
    int serv_len, clien_len;
    int port = atoi(argv[1]);

    // 创建套接字
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    // 初始化服务器 sockaddr_in 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;                   // 地址族 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // 监听本机所有的IP
    serv_addr.sin_port = htons(port);            // 设置端口 
    serv_len = sizeof(serv_addr);
    // 绑定IP和端口
    bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

    // 设置同时监听的最大个数
    listen(lfd, 36);
    printf("Start accept ......\n");

    // 创建红黑树根节点
    int epfd = epoll_create(2000);
    if(epfd == -1)
    {
        perror("epoll_create error");
        exit(1);
    }
    // lfd添加到监听列表
    SockInfo* sinfo = (SockInfo*)malloc(sizeof(SockInfo));
    sinfo->sock = serv_addr;
    sinfo->fd = lfd;
    struct epoll_event ev;
    ev.data.ptr = sinfo;
    ev.events = EPOLLIN;
    int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    if(ret == -1)
    {
        perror("epoll_ctl error");
        exit(1);
    }

    struct epoll_event res[2000];
    while(1)
    {            
        // 设置监听
        ret = epoll_wait(epfd, res, sizeof(res)/sizeof(res[0]), -1);
        if(ret == -1)
        {
            perror("epoll_wait error");
            exit(1);
        }

        // 遍历前ret个元素
        for(int i=0; i<ret; ++i)
        {
            int fd = ((SockInfo*)res[i].data.ptr)->fd;
            if(res[i].events != EPOLLIN)
            {
                continue;
            }
            // 判断文件描述符是否为lfd
            if(fd == lfd)
            {
                char ipbuf[64];
                SockInfo *info = (SockInfo*)malloc(sizeof(SockInfo));
                clien_len = sizeof(clien_addr);
                cfd = accept(lfd, (struct sockaddr*)&clien_addr, &clien_len);
                // cfd 添加到监听树
                info->fd = cfd;
                info->sock = clien_addr;
                struct epoll_event ev;
                ev.events = EPOLLIN;
                ev.data.ptr = (void*)info;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                printf("client connected, fd = %d, IP = %s, Port = %d\n", cfd, 
                       inet_ntop(AF_INET, &clien_addr.sin_addr.s_addr, ipbuf, sizeof(ipbuf)), 
                       ntohs(clien_addr.sin_port));
            }
            else
            {
                // 通信
                char ipbuf[64];
                char buf[1024] = {0};
                int len = recv(fd, buf, sizeof(buf), 0);
                SockInfo* p = (SockInfo*)res[i].data.ptr;
                if(len == -1)
                {
                    perror("recv error");
                    exit(1);
                }
                else if(len == 0)
                {
                    // ip
                    inet_ntop(AF_INET, &p->sock.sin_addr.s_addr, ipbuf, sizeof(ipbuf));
                    printf("client %d 已经断开连接, Ip = %s, Port = %d\n", 
                           fd, ipbuf, ntohs(p->sock.sin_port));
                    // 节点从树上删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    free(p);
                }
                else
                {
                    printf("Recv data from client %d, Ip = %s, Port = %d\n", 
                           fd, ipbuf, ntohs(p->sock.sin_port));
                    printf("    === buf = %s\n", buf);
                    send(fd, buf, strlen(buf)+1, 0);
                }
            }
        }
    }

    close(lfd);
    free(sinfo);
    return 0;
}
