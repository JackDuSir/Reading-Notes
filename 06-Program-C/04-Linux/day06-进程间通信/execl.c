#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("./fpe","fpe",NULL);

    printf("bye bye!\n");
    return 0;
}

