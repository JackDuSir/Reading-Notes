/*************************************************************************
	> File Name: server_tcp.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月09日 星期二 16时32分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

// 进程回收函数
void recyle(int num)
{
    pid_t pid;
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        printf("child died, pid = %d\n", pid);
    }
}

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

    // 绑定 ip 和端口
    bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

    // 设置同时监听的最大个数
    listen(lfd, 36);
    printf("Start accept ......\n");

    // 使用信号回收子进程 pcb
    struct sigaction act;
    act.sa_handler = recyle;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD, &act, NULL);

    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    while (1) {
        // 父进程接受链接请求
        // accept 阻塞的时候被信号中断，处理信号队形的操作之后，
        // 回来之后不阻塞了，直接返回 -1，这时候 errno = EINTR
        int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);
        while (cfd == -1 && errno == EINTR) {
            cfd = accept(lfd, (struct sockaddr*)&cli_addr, &cli_len);

        }
        printf("connect successful\n");

        // 创建子进程
        pid_t pid = fork();
        if (pid == 0) {
            // child process
            close(lfd);
            //通信
            char ip[64];
            while (1) {
                // client ip potr
                printf("client IP: %s, Port: %d\n",
                       inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, sizeof(ip)),
                       ntohs(cli_addr.sin_port));
                char buf[1024];
                int len = read(cfd, buf, sizeof(buf));
                if (len == -1) {
                    perror("read error");
                    exit(1);
                } else if (len == 0) {
                    printf("客户端断开了连接\n");
                    close(cfd);
                    break;
                } else {
                    printf("recv buf: %s\n",buf);
                    write(cfd, buf, len);
                }
            }
            // 干掉子进程
            return 0;
        } else if (pid > 0) {
            // parent process
            close(cfd);
        }
    }
    close(lfd);
    
    return 0;
}

