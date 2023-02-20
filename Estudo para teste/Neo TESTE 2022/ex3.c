#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    mkfifo("fifo",0644);
    int status,pid,n,cli;
    while(1)
    {
        int cli = open("fifo", O_RDONLY);

        pid = fork();
        if(pid==0)
        {
            execlp("cmd","cmd",NULL);
        }
        wait(&status);
        if(WIFEXITED(status)==0){
            sleep(10);
            if(WIFEXITED(status)==0)
            {
                kill(pid, SIGTERM);
                printf("%d",WEXITSTATUS(status));
            }
        }
    }
}