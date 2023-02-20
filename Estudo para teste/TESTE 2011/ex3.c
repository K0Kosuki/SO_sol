#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int status, n, pid;
    int count = 0;
    char buf[1024];
    int pd[2];
    pipe(pd);
    for (int i = 2; i < argc; i++)
    {

        int fd = open(argv[i], O_RDONLY);
        dup2(fd,0);
        if (read(fd, buf, sizeof(buf)) > 0)
            ;
        pid = fork();

        if (pid == -1)
        {
            perror("error");
            _exit(1);
        }
        if (pid == 0)
        {
            close(pd[0]);
            dup2(pd[1],1);
            execlp("oc","oc",argv[i],NULL);
            close(pd[1]);
            exit(0);
        }
            else
            {
                
            }




        count++;
    }
   
    while (count > 0)
    {
         wait(&status);
    }
  
    
}