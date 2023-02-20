#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    pid_t pid, filho, pai;
    pid = fork();

    filho = getpid();
    pai = getppid();
    printf("id do filho %d\n", filho);
    printf("id do pai %d\n", pai);
    int s;
    switch (pid)
    {
    case -1:
        perror("fork");
        exit(1);
        break;

    case 0://é filho
        printf("filho = %d,pai =%d\n", filho, pai);
        return 10;
        
    default:
        printf("filho = %d,pai = %d\n", filho, pai);
        wait(&s);
        if (WIFEXITED(s))
        {
            printf("filho terminou com %d\n", WEXITSTATUS(s));
        }
        
        break;
    }

    
    return 0;
}