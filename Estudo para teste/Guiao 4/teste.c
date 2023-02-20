#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int n;
    char buf[256];

    int in = open("input.txt",O_RDONLY);
    int out = open("output.txt",O_WRONLY | O_CREAT,0644);

    
    printf("res in: %d\n",in);
    printf("res: %d\n",out);
    dup2(in,STDIN_FILENO);
    dup2(out,STDOUT_FILENO);
    printf("res: %d\n",out);
    close(in);
    close(out);

    

    execl("/bin/cat","cat",(char*)0);

}