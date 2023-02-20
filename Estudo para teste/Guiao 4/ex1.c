#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int n;
    char c[20];
    int in = open("password.txt", O_RDONLY);
    if (in == -1)
    {
        perror("error opening password!");
        return -1;
    }
     dup2(in, STDIN_FILENO);
    int out = open("saida1.txt", O_WRONLY | O_CREAT ,0644);
     dup2(out, STDOUT_FILENO);
    int err = open("erro.txt", O_WRONLY | O_CREAT, 0644);


    dup2(err, STDERR_FILENO);

    while ((n=read(0,c,sizeof(char)))>0)
    {
        write(1,c,n);
    }
    

    close(in);
    close(out);
    close(err);
}
