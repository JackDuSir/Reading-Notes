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
    int lfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (lfd == -1) {
        perror("socket error");
        exit(1);
    }

    // 如果套接字文件存在，删除套接字文件
    unlink("server.sock");

    // 绑定
    struct sockaddr_un serv;
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path, "server.sock");
    int ret = bind(lfd, (struct sockaddr*)&serv, sizeof(serv));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    ret = listen(lfd, 36);
    if (ret == -1) {
        perror("listen error");
        exit(1);
    }
    
    struct sockaddr_un cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);
    if (cfd == -1) {
        perror("accept error");
        exit(1);
    }
    printf("client bind file: %s\n", cli_addr.sun_path);

    while (1) {
        char buf[1024] = {0};
        int recvlen = recv(cfd, buf, sizeof(buf), 0);
        if (recvlen == -1) {
            perror("recv error");
            exit(1);
        } else if (recvlen == 0) {
            printf("client disconnect ...\n");
            close(cfd);
            break;
        } else {
            printf("recv buf: %s\n", buf);
            send(cfd, buf, recvlen, 0);
        }
    }
    close(cfd);
    close(lfd);

    return 0;
}

