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

    // 初始化服务器的IP和端口
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);

    // 通信
    while (1) {
        char buf[1024] = {0};
        printf("请输入要发送的数据：");
        fgets(buf, sizeof(buf), stdin);
        // 数据的发送 - server - IP port
        sendto(fd, buf, strlen(buf)+1, 0, (struct sockaddr*)&serv, sizeof(serv));

        // 等待服务器发送数据过来
        recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        printf("recv buf: %s\n", buf);
    }
    close(fd);

    return 0;
}

