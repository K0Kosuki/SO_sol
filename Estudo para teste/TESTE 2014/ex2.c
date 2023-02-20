#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int time = atoi(argv[1]);
    int size = atoi(argv[2]);
    int status, n, pid;
    char buf[size];
     int total=0;
int fd = open(argv[1], O_RDONLY);
 dup2(fd, STDIN_FILENO);
    pid = fork();
    if (pid == 0)
    {
        
       
        execlp(argv[3],argv[3],NULL);
        close(fd);
    }else
    {
        wait(&status);
        if (WIFEXITED(status)==0)
        {
            sleep(time);
            if(WIFEXITED(status)==0)
            {
                kill(pid, SIGKILL);
            }
        }
        while((n=read(fd,buf,sizeof(buf)))>0)
        {
           total+= n;
           if(total>size){
            kill(pid, SIGKILL);
           }
        }

    }
    return 0;
}