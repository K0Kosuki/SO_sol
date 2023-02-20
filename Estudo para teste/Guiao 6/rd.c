#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int n;
    char buf[1024];
    int fd = open("fifo", O_RDONLY);

    while ((n=read(fd, buf, sizeof(buf)))>0)
    {
        write(1,buf,n);
    }
    return 0;
}