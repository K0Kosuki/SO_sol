#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int executa_script(const char *nome_ficheiro)
{
   FILE* ficheiro = fopen(nome_ficheiro, "r");
   if(ficheiro == NULL){
    perror("error opening");
    exit(-1);
   }
   char n;

char buffer[256];
pid_t pid = fork();
int pd[2];
pipe(pd);

while(n=read(ficheiro, buffer, sizeof(buffer))<0)
{
    char nome =strtok(buffer, " ");
    char caminho =strtok(NULL, " ");
}



}