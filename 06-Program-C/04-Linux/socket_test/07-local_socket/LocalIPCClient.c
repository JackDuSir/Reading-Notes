/*************************************************************************
	> File Name: LocalIPCServer.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月11日 星期四 16时41分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/un.h>

int main(int argc, char *argv[])
{
    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket error");
        exit(1);
    }

    // 如果套接字文件存在，删除套接字文件
    unlink("client.sock");

    // 给客户端绑定一个套接字文件
    struct sockaddr_un client;
    client.sun_family = AF_LOCAL;
    strcpy(client.sun_path, "client.sock");
    int ret = bind(fd, (struct sockaddr*)&client, sizeof(client));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    // 初始化 server 信息
    struct sockaddr_un serv;
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path, "server.sock");

    connect(fd, (struct sockaddr*)&serv, sizeof(serv));

    while (1) {
        char buf[1024] = {0};
        printf("请输入要发送的数据：");
        fgets(buf, sizeof(buf), stdin);
        send(fd, buf, strlen(buf)+1, 0);
        
        // 接受数据
        recv(fd, buf, sizeof(buf), 0);
        printf("recv buf: %s\n", buf);
    }
    close(fd);

    return 0;
}

