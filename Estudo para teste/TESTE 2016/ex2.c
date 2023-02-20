#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int status;
    int pid, n, fd;
    char buf[256];
    int num = 0;
    for (int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if ((read(fd, buf, sizeof(buf))) > 0)
        {
            dup2(fd,0);
            pid = fork();
            if (pid == 0)
            {
                execlp("CTRL", "CTRL", NULL);
                exit(0);
            }
        }
        num++;
        
    }
    while (num-1>0)
    {
        wait(&status);
        if (WIFEXITED(status) == 0)
        {
            sleep(3);
            if (WIFEXITED(status) == 0){
                kill(pid, SIGKILL);
          

        }
    }
    close(fd);
    
}