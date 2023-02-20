#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    mkfifo("fifo", 0644);
    open("fifo", O_RDONLY);
    int n, pid, status;
    pid = fork();

   int cli = open("fifo", O_RDONLY);
if (cli < 0) {
    perror("error");
    exit(1);
}

    while (1)
    {
        char buf[1024];
        if (n = read("fifo", buf, sizeof(buf)) > 0)
            ;

        if (pid == -1)
        {
            perror("error fork");
            _exit(1);
        }
        else if (pid == 0)
        {
           execl("curl","curl",NULL);
           if((execl("curl","curl",NULL))<0){
            perror("error curl");
            _exit(1);
           }
        }else
        {
            wait(&status);
            if(WIFEXITED(status)==1)
            {
                if(WEXITSTATUS(status)== 0)
                {
                    printf("success");
                }
            }else{
                printf("error");
            }
        }
    }
}