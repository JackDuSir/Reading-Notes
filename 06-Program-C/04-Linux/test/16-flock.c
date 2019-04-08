/*************************************************************************
	> File Name: 16-flock.c
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 2019年04月08日 星期一 19时18分13秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define _FILE_NAME_ "/home/miaopei/temp.lock"


int main(int argc, char *argv[])
{
    int fd = open(_FILE_NAME_, O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open err");
        return -1;
    }
    struct flock lk;
    lk.l_type = F_WRLCK;
    lk.l_whence = SEEK_SET;
    lk.l_start = 0;
    lk.l_len = 0;

    if (fcntl(fd, F_SETLK, &lk) < 0) {
        perror("get lock err");
        exit(1);
    }
    // 核心逻辑
    while (1) {
        printf("I am alive!\n");
        sleep(1);
    }    

    return 0;
}

