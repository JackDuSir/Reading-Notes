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
#include <sys/select.h>

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

    // 最大的文件描述符
    int maxfd = lfd;
    // 文件描述符读写集合
    fd_set reads, temp;
    // init 
    FD_ZERO(&reads);
    FD_SET(lfd, &reads);
    
    while (1) {
        // 委托内核做 IO 检测
        temp = reads;
        int ret = select(maxfd+1, &temp, NULL, NULL, NULL);
        if (ret == -1) {
            perror("select error");
            exit(1);
        }

        // 客户端发起了新的连接
        if (FD_ISSET(lfd, &temp)) {
            // 接受链接请求 - accept 不阻塞
            int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);
            if (cfd == -1) {
                perror("accept error");
                exit(1);
            }

            char ip[64];
            printf("client IP: %s, Port: %d\n",
                   inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                   ntohs(cli_addr.sin_port));

            // 将 cfd 加入到待检测的读集合中 - 下一次就可以检测到了
            FD_SET(cfd, &reads);
            // 更新最大的文件描述符
            maxfd = maxfd < cfd ? cfd : maxfd;
        }

        // 已经连接的客户端有数据到达
        for (int i=lfd+1; i <= maxfd; ++i) {
            if (FD_ISSET(i, &temp)) {
                char buf[1024] = {0};
                int len = recv(i, buf, sizeof(buf), 0);
                if (len == -1) {
                    perror("recv error");
                    exit(1);
                } else if (len == 0) {
                    char ip[64];
                    printf("客户端[%s:%d]已经断开了连接\n",
                           inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                           ntohs(cli_addr.sin_port));
                    close(i);

                    // 从读集合中删除
                    FD_CLR(i, &reads);
                } else {
                    printf("recv buf: %s\n", buf);
                    send(i, buf, strlen(buf)+1, 0);
                }
            }
        }

    }
    close(lfd);
 
    return 0;
}

