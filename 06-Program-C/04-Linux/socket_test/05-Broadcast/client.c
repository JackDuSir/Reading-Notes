/*************************************************************************
	> File Name: client.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月11日 星期四 15时18分01秒
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
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket error");
        exit(1);
    }

    // 绑定IP和端口
    struct sockaddr_in cli_addr;
    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(6767);
    inet_pton(AF_INET, "0.0.0.0", &cli_addr.sin_addr.s_addr);
    
    int ret = bind(fd, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    // 接受数据
    while (1) {
        char buf[1024] = {0};
        int len = recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        if (len == -1) {
            perror("recvfrom error");
            break;
        }
        printf("client == recv buf: %s\n", buf);
    }
    close(fd);

    return 0;
}

