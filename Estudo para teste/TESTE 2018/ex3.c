#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv){
    int fd = open(argv[1], O_RDONLY | O_CREAT,0666);
    char buffer[256];
    pid_t pid = fork();
    
}