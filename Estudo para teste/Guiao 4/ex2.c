#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    char c[100];
    int n;
   int pid = fork();
    int in = open("password.txt", O_RDONLY);
    if (in == -1)
    {
        perror("error opening password!");
        return -1;
    }
    dup2(in, STDIN_FILENO);
    int out = open("saita.txt", O_WRONLY | O_CREAT ,0644);
     dup2(out, STDOUT_FILENO);
    int err = open("error.txt", O_WRONLY | O_CREAT, 0644);
    dup2(err, STDERR_FILENO);


    if (pid==0)
    {
       while ((n=read(STDIN_FILENO,c,sizeof(c)))>0)
       {
        write(STDOUT_FILENO,c,n);
       }
       
    }
    wait(NULL);
    close(in);
    close(out);
    close(err);
}
