#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int status,pid,n,in,out;
    char buf[1024];
    int out = open("out", O_WRONLY | O_CREAT, 0644);
    for(int i =2 ; i<11 ;i+=2)
    {
        pid = fork();
        if(pid == 0){
        in = open(argv[i],O_RDONLY);
        dup2(in,0);
        dup2(out,1);
        execlp(argv[1],argv[i],NULL);
        }
        else{
            wait(&status);
            if(WIFEXITED(status)==0)
            {
                printf("SUCCESSFUL\n");
            }
        }
    }
    while ((n=read(out,buf,sizeof(buf)))>0)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(buf[i] == read("out",buf,sizeof(buf)))
            {
                printf("success\n");
            }
        }
    }
}