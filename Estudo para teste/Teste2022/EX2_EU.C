#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    int pidm, pidv, fd;

    int M = open("M.gz", O_WRONLY | O_CREAT | O_TRUNC);
    int V = open("V.gz", O_WRONLY | O_CREAT | O_TRUNC);

    int pdm[2], pdv[2];
    int n;
    char buf[1024];

    pipe(pdm);
    pipe(pdv);

    pidm = fork();
    pidv = fork();

    fd = open(argv[1], O_RDONLY);
    dup2(fd, 0);

    if (pidm == 0)
    {
        close(fd);
        close(pdm[0]);
        dup2(pdm[0], 0);
        dup2(M, 1);
        execlp("gzip", "gzip", NULL);
        exit(0);
    }
    if (pidv == 0)
    {
        close(fd);
        close(pdv[0]);
        dup2(pdv[0], 0);
        execlp("gzip", "gzip", "V.gz", NULL);
    }
    else
    {
        while ((n = read(fd, buf, sizeof(buf))) > 0)
        {
            if(buf[0] == 'M')
            {
                close(pdm[0]);
                write(pdm[1], buf, n);
            }
            else if(buf[0=='V'])
            {
                close(pdv[0]);
                write(pdv[1], buf,n);
            }
        }
    }
}