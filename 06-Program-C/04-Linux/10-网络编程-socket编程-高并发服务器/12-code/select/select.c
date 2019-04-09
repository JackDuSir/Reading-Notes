#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/select.h>

#define SERV_PORT 8989

int main(int argc, const char* argv[])
{
    int lfd, cfd;
    struct sockaddr_in serv_addr, clien_addr;
    int serv_len, clien_len;

    // 创建套接字
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    // 初始化服务器 sockaddr_in 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;                   // 地址族 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // 监听本机所有的IP
    serv_addr.sin_port = htons(SERV_PORT);            // 设置端口 
    serv_len = sizeof(serv_addr);
    // 绑定IP和端口
    bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

    // 设置同时监听的最大个数
    listen(lfd, 36);
    printf("Start accept ......\n");

    int ret;
    int maxfd = lfd;
    // reads 实时更新，temps　内核检测
    fd_set reads, temps;

    FD_ZERO(&reads);
    FD_SET(lfd, &reads);

    while(1)
    {
        temps = reads;
        ret = select(maxfd+1, &temps, NULL, NULL, NULL);
        if(ret == -1)
        {
            perror("select error");
            exit(1);
        }


        // 判断是否有新连接
        if(FD_ISSET(lfd, &temps))
        {
            // 接受连接请求
            clien_len = sizeof(clien_len);
            int cfd = accept(lfd, (struct sockaddr*)&clien_addr, &clien_len);

            // 文件描述符放入检测集合
            FD_SET(cfd, &reads);
            // 更新最大文件描述符
            maxfd = maxfd < cfd ? cfd : maxfd;
        }

        // 遍历检测的文件描述符是否有读操作
        for(int i=lfd+1; i<=maxfd; ++i)
        {
            if(FD_ISSET(i, &temps))
            {
                // 读数据
                char buf[1024] = {0};
                int len = read(i, buf, sizeof(buf));
                if(len  == -1)
                {
                    perror("read error");
                    exit(1);
                }
                else if(len == 0)
                {
                    // 对方关闭了连接
                    FD_CLR(i, &reads);
                    close(i);
                    if(maxfd == i)
                    {
                        maxfd--;
                    }
                }
                else
                {
                    printf("read buf = %s\n", buf);
                    for(int j=0; j<len; ++j)
                    {
                        buf[j] = toupper(buf[j]);
                    }
                    printf("--buf toupper: %s\n", buf);
                    write(i, buf, strlen(buf)+1);
                }
            }
        }
    }

    close(lfd);
    return 0;
}
