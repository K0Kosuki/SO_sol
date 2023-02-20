#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    dup2(fd, STDIN_FILENO);
    int pd[2];
    pipe(pd);
    int n, pid, count = 0;
    char buf[128];
    pid = fork();

    for (int i = 0; i < 8; i++)
    {
        if (pid == 0)
        {
            close(pd[1]);
            dup2(pd[0], STDIN_FILENO);
            execlp("patgrep", "patgrep", NULL);
        }
    }
    else
    {
        close(pd[0]);
        whlie((n = read(fd, buf, sizeof(buf))) > 0)
        {
            write(pb[1], buf, sizeof(buf));
        }
        close(pd[1]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    dup2(fd, STDIN_FILENO);
    int pd[2], estado;
    pipe(pd);
    int n, pid, count = 0;
    char buf[128];
    pid = fork();

    for (int i = 0; i < 8; i++)
    {
        if (pid == 0)
        {
            close(pd[1]);
            dup2(pd[0], STDIN_FILENO);
            execlp("patgrep", "patgrep", NULL);
        }
    }

    close(pd[0]);
    while((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(pd[1], buf, sizeof(buf));
    }
    close(pd[1]);

    for (int i = 0; i < 8; i++)
    {
        wait(&estado);
        
    }

    while (read(pd[1],buf, sizeof(buf))>0)
    {
        for(int i = 0; i < sizeof(buf); i++){
            if (buf[i] == 'X')
            {
                count++;
            }
        }
    }
    
    printf("%d",count);
    
}