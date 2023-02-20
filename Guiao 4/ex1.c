#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd,fd1,fd2,fd3;
	int dup(int fd);
	int dup2(int fd1, int fd2);

	fd1 = open("/etc/passwd", O_RDONLY);
	fd2 = open("saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fd3 = open("erros.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	dup2(fd1, 0);
	close(fd1);
	dup2(fd2, 1);
	close(fd2);
	dup2(fd3, 2);
	close(fd3);
    write(1,"terminei",8);
	return 0;
}
