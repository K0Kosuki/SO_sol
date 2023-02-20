#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

void create_captcha_file(const char* palavra)
{
    int pid = fork();
}


int main(int argc, char* argv[])
{
    mkfifo("fifo",0644);
    char buf[16384];
    char palavra[6],id;
    int n;
    int cli = open("fifo", O_RDONLY);
}