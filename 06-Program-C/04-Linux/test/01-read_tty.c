/*************************************************************************
	> File Name: read_tty.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月02日 星期二 20时03分21秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd = open("/dev/tty", O_RDWR|O_NONBLOCK);

    char buf[256];
    int ret = 0;
    while(1) {
        ret = read(fd, buf, sizeof(buf));
        if (ret) {
            printf("buf is %s\n", buf);
        }
        sleep(1);
    }
    close(fd);
    return 0;
}

