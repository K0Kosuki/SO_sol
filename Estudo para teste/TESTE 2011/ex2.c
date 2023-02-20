#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int S = atoi(argv[2]);;
    int n, pid, status;
    char buf[256];
    int count = 0;

    for (int i = 3; i < N; i++)
    {
        int fb = open(argv[i], O_RDONLY);
        if (read(fb, buf, sizeof(buf)) > 0)
            ;
        pid = fork();

        if (pid == 0)
        {
            execlp(argv[i],argv[i],NULL);
            exit(0);
        }
        count++;
    }
    while(count > 0){
        wait(&status);
        if (WIFEXITED(status) == 0){
            sleep(S);
            if (WIFEXITED(status) == 0)
            {
                kill(pid,SIGKILL);
            }
            count--;
        }
    }
    return 0;
}