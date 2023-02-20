#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char palavra = atoi(argv[1]);
    int in = open(argv[2], O_RDONLY);
    int out = open("saida", O_WRONLY | O_CREAT ,0644);
    dup2(in,0);
    int status;
    int total = 0;
    
    int s = 0;
    int pid,n,pd[2];
    char buf[100];

    for(int i=0; i<10; i++){
       
     if(readln(in,buf,100)>0);
       pid=fork();
        if(pid==0){
            
            dup2(out,1);
            execlp("agrep","agrep",palavra,argv[2],NULL);
            close(1);
            exit(0);
            s++;
        }
        else
        {
            
            while (s>10)
            {
               wait(&status);
               if(WIFEXITED(status)==0)
               {
                sleep(60);
                if(WIFEXITED(status)==0)
                {
                    kill(pid,SIGKILL);
                }
               }
               s--;
            }
            
            
            return 0;
        }
        

        
        
    }
}