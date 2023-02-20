#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int n;
    char buf[1024];
    int fd = open("fifo", O_WRONLY);

    while ((n=read(0, buf, sizeof(buf)))>0)
    {
        write(fd,buf,n);
    }
    return 0;
}