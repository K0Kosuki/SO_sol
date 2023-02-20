#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int *status);
pid_t waitPID(pid_t pid, int *status, int options);
int WIFEXITED(int status);
int WEXITSTATUS(int status);*/

int main()
{
 pid_t pai,filho;
  
  
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("erro\n");
        perror;
    }
    else if (pid == 0)
    {
        printf("e'filho %d:\n", pid);
        filho = getpid();
        exit(0);
    }
    else
    {
        printf("pai no pid: %d", pid);
        pai = getppid();
        printf("%d\n",pai);
    }
}