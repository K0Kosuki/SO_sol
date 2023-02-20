
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include<sys/wait.h> 


int main(){
int pipe_voices[2], pipe_messages[2];
    pid_t gzip_voice, gzip_message;


    pipe(pipe_voices);
    pipe(pipe_messages);
    gzip_voice = fork();
    if(gzip_voice==0){
        close(pipe_voices[1]);
        dup2(pipe_voices[0],0);
        close(pipe_voices[0]);
        execpl("gzip","gzip",NULL);
    }
    else{
        if(gzip_message==0)
        {
            close(pipe_messages[1]);
            dup2(pipe_messages[0],0);
            close(pipe_messages[0]);
            execpl("gzip","gzip",NULL);
        }
    }else{
        close(pipe_voices[0]);
            close(pipe_messages[0]);
            char line[1024];
            int n;
            while (n=read(pipe_voices,line,sizeof(line))>0)
            {
               write(pipe_voices[1],line,sizeof(line));
            }
            
    }
}