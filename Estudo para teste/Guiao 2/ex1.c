#include <unistd.h>
#include <sys/wait.h>

#define MAX 
int main()
{
pid_t pid,pai,filho;

    filho = getpid();
    pai = getppid();
    printf("id do filho %d\n", filho);
    printf("id do pai %d\n", pai);


if ((pid = fork()) ==0)
{
   printf("filho\n");
   exit(1);
}
if ((pid = fork()) == 1)
{
    printf("pai\n");
}


}