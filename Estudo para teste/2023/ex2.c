#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int status, pid, n;
    int out = open("out", O_WRONLY | O_CREAT, 0644);
    char buf[1024];
    for (int i = 2; i < 11; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            int in = open(argv[i], O_RDONLY);
            dup2(in, 0);
            dup2(out, 1);
            execlp(argv[1], argv[1]);
            close(in);
        }

        else
        {
            wait(&status);
            if (WEXITSTATUS(status) == 0)
            {
                printf("sucesso");
            }
            
            while ((n = read(out, buf, sizeof(buf))) > 0)
            {
                write(out, buf, n);
            }

            for (int i = 0; i < n; i++)
            {
            if(buf[i] == read(out,buf[i],sizeof(buf))
            {
                    printf("sucesso test");
            }
            }
        }
    }

    return 0;
}