/*************************************************************************
	> File Name: xx.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月11日 星期四 14时43分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <net/if.h>

int main(int argc, char *argv[])
{
    // 绑定套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket error");
        exit(1);
    }

    // 绑定server的IP和端口
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8787);    // server 端口
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(fd, (struct sockaddr*)&serv, sizeof(serv));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    // 初始化客户端地址信息
    struct sockaddr_in cli_addr;
    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(6767); // 客户端要绑定的端口
    // 使用组播地址给客户端发送数据
    inet_pton(AF_INET, "239.0.0.10", &cli_addr.sin_addr.s_addr);

    // 给服务器开放组播权限
    struct ip_mreqn flag;
    // init flag
    inet_pton(AF_INET, "239.0.0.10", &flag.imr_multiaddr.s_addr); // 组播地址
    inet_pton(AF_INET, "0.0.0.0", &flag.imr_address.s_addr); // 本地IP
    flag.imr_ifindex = if_nametoindex("enp0s31f6");
    setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, &flag, sizeof(flag));

    // 通信
    while (1) {
        // 一直给客户端发数据
        static int num = 0;
        char buf[1024] = {0};
        sprintf(buf, "hello, udp == %d\n", num++);
        int ret = sendto(fd, buf, sizeof(buf), 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
        if (ret == -1) {
            perror("sendto error");
            break;
        }

        printf("server == send buf: %s\n", buf);
        sleep(1);
    }
    close(fd);

    return 0;
}

