/*************************************************************************
	> File Name: select.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月10日 星期三 14时46分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/epoll.h>
#include <fcntl.h>

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

    // 设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 绑定 ip 和端口
    bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

    // 设置同时监听的最大个数
    listen(lfd, 36);
    printf("Start accept ......\n");

    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    // epoll 树根节点
    int epfd = epoll_create(3000);
    // 初始化 epoll 树
    // 监听的 lfd 挂到 epoll 树上
    struct epoll_event ev;
    // 在 ev 中init lfd 信息
    ev.events = EPOLLIN;
    ev.data.fd = lfd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);

    // 存储发送变化的 fd 对应信息
    struct epoll_event all[3000];
    
    while (1) {
        // 委托内核检测事件
        int ret = epoll_wait(epfd, all, sizeof(all)/sizeof(all[0]), -1);
        printf("================= epoll wait =================\n");

        // 遍历 all 数组中的前 ret 个元素
        for (int i = 0; i < ret; ++i) {
            int fd = all[i].data.fd;
            // 判断是否有新的连接
            if (fd == lfd) {
                // 接受链接请求 - accept 不阻塞
                int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);
                if (cfd == -1) {
                    perror("accept error");
                    exit(1);
                }

                // 设置文件cfd 为非阻塞模式
                int flag = fcntl(cfd, F_GETFL);
                flag |= O_NONBLOCK;
                fcntl(cfd, F_SETFL, flag);

                // 将新得到的 cfd 挂到树上
                struct epoll_event temp;
                // 设置边沿触发
                temp.events = EPOLLIN | EPOLLET;
                temp.data.fd = cfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &temp);

                // 打印客户端信息
                char ip[64];
                printf("client IP: %s, Port: %d\n",
                        inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                        ntohs(cli_addr.sin_port));
            } else {
                // 处理已经连接的客户端发送过来的数据
                if (!(all[i].events & EPOLLIN)) {
                    continue;
                }

                // 读数据
                char buf[5] = {0};
                int len;
                while ((len =recv(fd, buf, sizeof(buf), 0)) > 0) {
                    // 数据打印到终端
                    write(STDOUT_FILENO, buf, len);
                    // 发送给客户端
                    send(fd, buf, len, 0);
                }
                if (len == 0) {
                    char ip[64];
                    printf("客户端[%s:%d]已经断开了连接\n",
                           inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                           ntohs(cli_addr.sin_port));

                    // fd 从 epoll 树上删除
                    ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    if (ret == -1) {
                        perror("epoll_ctl - del error");
                        exit(1);
                    }

                    close(fd);
                } else if (len == -1) {
                    if (errno == EAGAIN) {
                        printf("缓存区数据已经读完\n");
                    } else {
                        printf("recv error ...\n");
                        exit(1);
                    }
                }
            }
        }
    }
    close(lfd);
 
    return 0;
}

