#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    int fd = open("mem.txt",O_RDWR);//创建并且截断文件
    //int fd = open("mem.txt",O_RDWR|O_CREAT|O_TRUNC,0664);//创建并且截断文件

    ftruncate(fd,8);   
    //创建映射区
   char *mem = mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //char *mem = mmap(NULL,8,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

    if(mem == MAP_FAILED){
        perror("mmap err");
        return -1;
    }
    close(fd);
    //拷贝数据
    strcpy(mem,"helloworld");
//    mem++;
    //释放mmap
    if(munmap(mem,20) < 0){
        perror("munmap err");
    }
    return 0;
}



