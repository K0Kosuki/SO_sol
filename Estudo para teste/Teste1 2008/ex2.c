#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv[])
{
    int status;
    int pid,n;
    char buf[255];
    int count =0;
    int num = 0;
    int pd[2];
    pipe(pd);
   
   for(int i=1; i<argc; i++){
    int fb=open(argv[i],O_RDONLY);
    
    if (read(fb,buf,255)>0);
    pid=fork();
    if(pid==0)
    {
        
        while ((n=read(pd[0],buf,255))>0)
        {
            close(pd[0]);
            dup2(pd[1],1);
            excelp("cl","cl",NULL);
            close(pd[1]);
        }
        
    }
    
    num++;
   }
   while (num-1>0)
   {
    wait(&status);
    int out = read(pd[0],buf,255);
    count+=atoi(buf);
   }

   
    
}