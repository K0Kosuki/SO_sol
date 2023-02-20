#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
    {
        mkfifo("ent", 0644);
        mkfifo("sai", 0644);

        int n = atoi(argv[2]);
        int status, num, count = 0, pid;
        char buf[512];
        int tempo =0;
        int in = open(argv[3], O_RDONLY);
        int out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        int ent = open("ent", O_WRONLY);
        int sai = open("sai", O_RDONLY);
        time_t start, end;

        for (int i = 0; i < n; i++)
        {
            pid = fork();
            if (pid == 0)
            {
                dup2(ent, STDIN_FILENO);
                dup2(sai, STDOUT_FILENO);
                execlp(argv[1], argv[1], NULL);
                exit(0);
            }
            else
            {
                while ((num = read(in, buf, 512)) > 0)
                {
                    write(ent, buf, num);
                }
                close(ent);
            }
        }
        while (count < n)
        {
            wait(&status);
            count++;
        }
        while ((num = read(sai, buf, 512)) > 0)
        {
            write(out, buf, num);
        }
        close(sai);
        for (int i = 0; i < num; i++)
        {
            tempo+= buf[i]; 
        }
        double media = tempo/num;
        
    }