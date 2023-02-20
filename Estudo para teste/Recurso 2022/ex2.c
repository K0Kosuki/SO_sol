#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int in = open("entrada.txt", O_RDONLY);
    int out = open("saida.txt",O_WRONLY| O_CREAT | O_TRUNC,0644);
    dup2(in, STDIN_FILENO);
    dup2(out, STDOUT_FILENO);
    int pid,n,status;
    char buf[1024];
    int ret =open("retorno.txt",O_WRONLY|O_CREAT | O_TRUNC,0644);

    pid = fork();
    if (pid < 0)
    {
        perror("error creating");
        _exit(1);
    }
    else if(pid == 0)
    {
        close(in);
        execlp("comando","comando",NULL);
        close(out);
    }
    wait(&status);
    while ((n=read(out,buf,sizeof(buf)))>0)
    {
       write(ret,WEXITSTATUS(status),sizeof(WEXITEDSTATUS(status)));
    }
    
return 0;
}