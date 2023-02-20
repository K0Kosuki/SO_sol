#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int pd[2];
    pipe(pd);
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        close(pd[1]);
        pd[0] = 3;
        pd[1] = 4;
        char buffer[512];
        int n;

        while ((n = read(pd[0], buffer, sizeof(buffer))) > 0)
        {
            write(1, buffer, n);
            close(pd[1]);
            _exit(0);
        }
    }
    close(pd[0]);
    write(pd[1], "ola", 3);
    close(pd[1]);
    wait(NULL);
    close(pd[1]);
    return 0;
}