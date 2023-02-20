#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int d1,d2,d3;
    char c[256];
    d1 = open("passwd",O_RDWR);
    d2 = open("saida.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);
    d3 = open("error.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);

    pid_t pid = fork();

    
    if(pid == 0)
    {
        while ((read(d1,c,sizeof(c)))>0)
        {
           write(d2,c,sizeof(c));
        }
        
        exit(0);
    }

    wait(NULL);

    dup2(d1,0);
    dup2(d2,1);
    dup2(d3,2);




    close(d1);
    close(d2);
    close(d3);
   
    return 0; 
}