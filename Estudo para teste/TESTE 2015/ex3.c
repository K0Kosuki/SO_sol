#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    mkfifo("ordenar", 0644);
    char buf[1024];
    int n;
   
    int in = open("ordenar", O_RDONLY);
   
   

    while (1)
    {
        if ((read("ordenar", buf, 1024)) > 0)
            ;
             int fd = open("name.txt", O_RDONLY);
              dup2(fd, STDIN_FILENO);
        int pid = fork();
        if (pid == 0)
        {
            close(0);
            int out = open("ordenar",O_WRONLY | O_CREAT);
            dup2(out,STDOUT_FILENO);
            execl("sort","sort",NULL);
        }
        wait(NULL);
        close(in);
        close(out);
         

    }
}