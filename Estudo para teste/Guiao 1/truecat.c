#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: mycat file1 [file2...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            perror(argv[i]);
            continue;
        }

        char buffer[BUFSIZE];
        ssize_t n;
        while ((n = read(fd, buffer, BUFSIZE)) > 0) {
            if (write(STDOUT_FILENO, buffer, n) == -1) {
                perror("write");
                return 1;
            }
        }

        if (n == -1) {
            perror("read");
            return 1;
        }

        if (close(fd) == -1) {
            perror("close");
            return 1;
        }
    }

    return 0;
}
