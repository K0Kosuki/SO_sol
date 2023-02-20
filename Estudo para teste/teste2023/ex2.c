#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int pd[2],pid,n;
    char buf[1024];
    double time =0;
    double media=0;
    int fd = open("message.dat",O_RDONLY);
    int saida = open("saida.dat",O_WRONLY,O_CREAT,0644);
    dup2(fd,STDIN_FILENO);
    dup2(saida,STDOUT_FILENO);

    pid = fork();
    if(pid < 0){
        perror("error processing");
        return 2;
    }
    if(pid==0){
        close(0);
        for (int i = 0; i < 10; i++)
        {
            while ((n=read(fd,buf,sizeof(buf)))>0)
            {
                execl("net-crypt","net-crypt",NULL);
            }
        }
        time+=milisegundos();
    }
    wait(NULL);
    close(fd);
    close(saida);
    media = time/10;
    return 0;

}