/*************************************************************************
	> File Name: 08-daemon.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 10时35分43秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    char strFileName[256] = {0};

    while (1) {
        memset(strFileName, 0x00, sizeof(strFileName));
        sprintf(strFileName, "%s/log/Mr.Miaow.%ld", getenv("HOME"), time(NULL));
        int fd = open(strFileName, O_RDWR | O_CREAT, 0666);
        if (fd < 0) {
            perror("open err");
            exit(1);
        }
        close(fd);
        sleep(5);
    }
    return 0;
}

