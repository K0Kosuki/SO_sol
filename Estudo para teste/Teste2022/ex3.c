#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int pid,status;
    mkfifo("fifo",0644);
    char buf[1024];
    pid=fork();

    while (1)
    {
        int cli = open("fifo", O_RDONLY);
        
       if(pid==0)
       {
        execl("cat","cat",NULL);
        exit(0);
       }
        else
        {
            wait(&status);
            if(WIFEXITED(status) ==0)
            {
                sleep(10);
                if(WIFEXITED(status) == 0)
                {
                    kill(pid, SIGKILL);
                }
            }
        }
    }
    
}