#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <event2/event.h>

void fifo_write(evutil_socket_t fd, short what, void* arg)
{
    printf("last arg value: %s\n", (char*)arg);

    // 读数据
    char buf[1024] = {0};
    read(fd, buf, sizeof(buf));
    printf("read data: %s\n", buf);

    printf("========================\n");
    printf("Read event: %s\n", what & EV_READ ? "Yes" : "No");
    printf("Write event: %s\n", what & EV_WRITE ? "Yes" : "No");
    printf("Persist event: %s\n", what & EV_PERSIST ? "Yes" : "No");

    printf("=========== %d\n", what);
}


int main(int argc, const char* argv[])
{
    unlink("myfifo");
    // 创建管道文件
    int ret = mkfifo("myfifo", 0664);
    if(ret == -1)
    {
        perror("mkfifo error");
        exit(1);
    }

    // 打开管道文件
    int fd = open("myfifo", O_RDONLY | O_NONBLOCK);
    if(fd == -1)
    {
        perror("open error");
        exit(1);
    }

    // 创建底层处理框架
    struct event_base* base = event_base_new();
    // 创建新事件
    struct event *rdev = event_new(base, fd, EV_READ | EV_PERSIST, 
                                   fifo_write, "read operation");
    // 添加时间到event_base
    event_add(rdev, NULL);

    // 事件循环
    event_base_dispatch(base);

    // 释放资源
    event_free(rdev);
    event_base_free(base);
    
    close(fd);
    
    return 0;
}
