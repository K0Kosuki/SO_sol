#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

void sig_handler(int signo)
{
    if (signo == SIGALRM)
    {
        kill(pid, SIGKILL);
    }
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, sig_handler);
    int status, pid, n;
    int num = 0;
    char buf[1024];
    for (int i = 1; i < argc; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            alarm(3);
            execlp(argv[i], argv[i], NULL);
            num++;
        }
        else
        {
            wait(&status);
            alarm(3);
        }
        while ((n = read(STDOUT_FILENO, buf, 1024)) > 0)
        {
            for (int i = 0; i < num; i++)
            {
                if (strstr(buf, "OK") != NULL)
                {
                    printf("ativa\n");
                }
                else
                {
                    printf("nao ativa\n");
                    kill(pid, SIGKILL);
                }
            }
        }
    }
    return 0;
}