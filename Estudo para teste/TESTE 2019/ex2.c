#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int n;
  int pid;
  int count = 0;
  int status;
  char buf[1024];
  int fd = open(argv[1], O_RDONLY);
for(int i = 0; i < 10; i++){
while (n=read(fd, buf, sizeof(buf))>0)
{
    char* aluno = strok(buf," ");
    char* nota  = strok(NULL," ");
    char* email = stract(aluno,"@aluno.uminho.pt");

     pid = fork();
        if(pid == 0)
        {
            execlp("mail","mail","-s","Sistemas_Operativos","email");
            perror("error");
            exit(1);
        }
        else
        {
            while(count -1>i)
            wait(&status);
            close(fd);
        }
}
count++;
}

    
    
       
    
    
 
  
}