#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int status,n,pid,fd;
    char palavra = atoi(argv[1]);
    char buf[1024];
    int pd[2];
    int total=0;
    for(int i=2;i<argc;i++)
    {
        if(read(argv[i],buf,sizeof(buf))>0);
        pid=fork();
        pipe(fd);
        if(pid==0)
        {
            close(pd[0]);
            dup2(pd[1],1);
            execl("encontra","encontra",NULL);
            close(pd[1]);
        }
        else
        {
            while ((n=read(pd[0],buf,sizeof(buf)))>0)
            {
                for(int i=0;i<n;i++)
                {
                    if(buf[i]=="\n")
                    {
                        total++;
                    }
                }
            }
            
        }
    }
}