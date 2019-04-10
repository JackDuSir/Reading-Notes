/*************************************************************************
	> File Name: server.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月10日 星期三 19时48分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("eg: %s port\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // 创建套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket error");
        exit(1);
    }

    // fd 绑定本地的IP和端口
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    // 设置端口复用
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    int ret = bind(fd, (struct sockaddr*)&serv, sizeof(serv));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    
    // 通信
    char buf[1024] = {0};
    while (1) {
        int recvlen = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr*)&cli_addr, &cli_len);
        if (recvlen == -1) {
            perror("recvfrom error");
            exit(1);
        }

        // 打印客户端信息
        char ip[64];
        printf("client IP: %s, Port: %d\n",
               inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
               ntohs(cli_addr.sin_port));

        printf("recv buf: %s\n", buf);
        // 给客户端发送数据
        sendto(fd, buf, strlen(buf)+1, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
    }
    close(fd);

    return 0;
}

