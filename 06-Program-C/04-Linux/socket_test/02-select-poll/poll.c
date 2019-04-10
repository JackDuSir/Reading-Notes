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
#include <poll.h>

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

    // poll 结构体
    struct pollfd allfd[1024];
    int max_index = 0;
    // init
    for (int i=0; i < 1024; ++i) {
        allfd[i].fd = -1;
    }
    allfd[0].fd = lfd;
    allfd[0].events = POLLIN;
    
    while (1) {
        int i = 0;
        int ret = poll(allfd, max_index+1, -1);
        if (ret == -1) {
            perror("poll error");
            exit(1);
        }

        // 判断是否有链接请求
        if (allfd[0].revents & POLLIN) {
            // 接受链接请求
            int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);
            if (cfd == -1) {
                perror("accept error");
                exit(1);
            }

            char ip[64];
            printf("client IP: %s, Port: %d\n",
                   inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                   ntohs(cli_addr.sin_port));

            // cfd 添加到 poll 数组
            for (i = 0; i < 1024; ++i) {
                if (allfd[i].fd == -1) {
                    allfd[i].fd = cfd;
                    break;
                }
            }

            // 更新最后一个元素的下标
            max_index = max_index < i ? i : max_index;
        }

        // 遍历数组
        for (i = 1; i <= max_index; ++i) {
            int fd = allfd[i].fd;
            if (fd == -1) {
                continue;
            }
            if (allfd[i].revents & POLLIN) {
                // 接受数据
                char buf[1024] = {0};
                int len = recv(fd, buf, sizeof(buf), 0);
                if (len == -1) {
                    perror("recv error");
                    exit(1);
                } else if (len == 0) {
                    char ip[64];
                    printf("客户端[%s:%d]已经断开了连接\n",
                           inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                           ntohs(cli_addr.sin_port));
                    allfd[i].fd = -1;
                    close(fd);
                } else {
                    printf("recv buf: %s\n", buf);
                    for (int k = 0; k < len; ++k) {
                        buf[k] = toupper(buf[k]);
                    }
                    printf("buf toupper: %s\n", buf);
                    send(fd, buf, strlen(buf)+1, 0);
                }

            }
        }
    }
    close(lfd);
 
    return 0;
}

