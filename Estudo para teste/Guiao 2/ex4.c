#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
pid_t pid,p1,p2,p3,p4;
int status;
pid=fork();
p1=getpid();
p2=getppid();
p3=getpid();
p4=getppid();
    if(pid==0){
    printf("im son my: %d   my father id : %d\n",p1,p2);
    _exit(0);
    }else 
    {
        waitpid(pid, &status,0);
        printf("im your mother fucker!!! : %d, my son id : %d\n",p3,p4);
    }
    
        if (WIFEXITED(status))
        {
            printf("son %d exit id : %d", pid, WEXITSTATUS(status));
        }
}