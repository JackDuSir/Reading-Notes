#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char * argv[])
{
    if(argc != 2){
        printf("./a.out fifoname\n");
        return -1;
    }
    
    // 当前目录有一个 myfifo 文件
    //打开fifo文件
    printf("begin open ....\n");
    int fd = open(argv[1],O_WRONLY);
    printf("end open ....\n");
    //写
    char buf[256];
    int num = 1;
    while(1){
        memset(buf,0x00,sizeof(buf));
        sprintf(buf,"xiaoming%04d",num++);
        write(fd,buf,strlen(buf));
        sleep(1);
        //循环写
    }
    //关闭描述符
    close(fd);
    return 0;
}


