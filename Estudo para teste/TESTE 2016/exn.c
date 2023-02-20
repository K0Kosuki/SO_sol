#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void timeout_handler(int signo) {
// 杀死子进程
kill(child_pid, SIGKILL);
}

int main() {
int child_pid = fork();
if (child_pid == 0) {
// 子进程
execlp("child_program", "child_program", NULL);
} else {
// 父进程
// 设置alarm
alarm(3);
// 设置SIGALRM信号的处理函数
signal(SIGALRM, timeout_handler);
// 等待子进程结束
waitpid(child_pid, NULL, 0);
}
return 0;
}