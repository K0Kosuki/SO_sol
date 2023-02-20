#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int out = open("saida.txt",O_WRONLY |O_CREAT,0644);
    dup2(out,1);
    int err = open("erro.txt",O_RDONLY |O_CREAT,0644);
    dup2(err,2);

    int in = open("password.txt", O_RDONLY);
    if (in == -1)
    {
        perror("error opening password!");
        return -1;
    }
    dup2(in,0);
    close(in);
    close(out);
    close(err);
    execlp("wc","wc",NULL);
	perror("erro no exec...");
	return -1;
}