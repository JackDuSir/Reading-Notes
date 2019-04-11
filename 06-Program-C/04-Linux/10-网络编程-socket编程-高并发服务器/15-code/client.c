#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <event2/event.h>

void cb_write(evutil_socket_t fd, short what, void* arg)
{
    printf("what = %d\n", what);
    while(1)
    {
        static int num = 0;
        char buf[1024] = {0};
        sprintf(buf, "hello world, %d\n", num++);
        write(fd, buf, strlen(buf)+1);
        sleep(1);
    }
}

int main(int argc, const char* argv[])
{
    int fd = open("myfifo", O_WRONLY);
    if(fd == -1)
    {
        perror("open error");
        exit(1);
    }

    struct event_base *base = event_base_new();
    struct event* ev = event_new(base, fd, EV_WRITE | EV_PERSIST, 
                                 cb_write, "this is write callback func!");
    event_add(ev, NULL);

    event_base_dispatch(base);

    event_free(ev);
    event_base_free(base);

    close(fd);
    
    return 0;
}
