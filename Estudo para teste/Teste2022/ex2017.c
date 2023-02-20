#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){

    int fd = open("pid.out",O_RDONLY |O_TRUNC|O_WRONLY,0666);
    int pid=fork();
    int estado;
    int pids[argc];
    for(int i=1;i<argc;i++){
    if(pid==-1) {
        perror("fork");
        exit(1);
    }
    if(pid==0) {
        dup2(fd,1);
        close(fd);
        execlp(argv[i],argv[i],NULL);
        perror("execlp");
        exit(-1);
    }
    pid[i]=pid;
    printf("E%d\n",pid);

    while (i<argc-1) 
    {
       wait(&estado);
       if(WIFEXITED(estado)!=0)
       {
        printf("S%d\n",estado);
       }
    }
    if()


    }

}