#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

int main(int argc, char* argv[])
{
	int d, de, n;

	char linha[MAX];

	d = open(argv[1], O_RDONLY);

	if(d == -1){
		perror("abertura ficheiro");
		exit(-1);
	}

	de = open(argv[2], O_WRONLY | O_CREAT, 0644);

	while((n = read(d, linha, MAX) > 0)){
		write(de, linha, n);
	}

	close(d);
	close(de);
	exit(0);
}
