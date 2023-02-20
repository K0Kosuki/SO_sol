#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int d1,d2,d3;
    char c;
    
    d1 = open("passwd",O_RDWR);
    d2 = open("saida.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);
    d3 = open("error.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);

    dup2(d1,0);
    close(d1);
    dup2(d2,1);
    close(d2);
    dup2(d3,2);
    close(d3);
    write(1,"end",3);
    return 0; 
}