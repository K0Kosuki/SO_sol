#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int status;
    int pid;
    int count =0;
    int out = open("pid.out", O_WRONLY | O_CREAT, 0644);
    dup2(out, STDOUT_FILENO);
    
    for (int i = 1; i < argc; i++)
    {
        pid = fork();
        if (fork == -1) /* code */
        {
            perror("fork failed");
            _exit(1);
        }
        else if (fork == 0)
        {
            

                execl(argv[i], argv[i], NULL);
                
                perror("execl failed");
                exit(1);
            
        }
        printf("E %d",getpid());
        count++;
    }
    while (count<argc);
    {
       wait(&status);
       if(WIFEXITED(status)){
        if(WEXITSTATUS(status)==0){
            printf("S %d",getpid());
        }
       }
       else
       {
        for(int i=0; i<argc; i++)
        {
            execl(argv[i],argv[i],NULL);
        }
        printf("R %d",getpid());
       }
    }
    
}