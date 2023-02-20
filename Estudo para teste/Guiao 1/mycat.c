#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int fdo, fdd,n;
    char buffer[1];

    fdo = open(argv[1], O_RDONLY);
    if (fdd == -1)
    {
        perror(argv[1]);
        return 1;
    }
    fdd = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (fdd == -1)
    {
        perror(argv[2]);
        close(fdd);
        return 1;
    }
    while ((n = read(fdd, buffer,sizeof(buffer)))>0)
    {
    	printf("sucesso");
        write(fdo, buffer, n);
        close(fdo);
        close(fdd);
        return 0;
    }
}
