#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int fd = mkfifo("fifo",0644);
    if(fd <0){
        perror("error creating fifo");
    }
}