#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pd[2]; 
    int ret = pipe(pd); // 创建管道 

    if (ret == -1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork(); //创建子进程
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        close(pd[1]); // 关闭写端
        char buf[20];
        int n = read(pd[0], buf, sizeof(buf)); 
        printf("子进程读到了：%.*s\n", n, buf);
        close(pd[0]); 
    }
    else
    {
        //父进程
        close(pd[0]); // 关闭读端
        sleep   (5);
        const char *msg = "hello";
        write(pd[1], msg, sizeof(msg)); 
        close(pd[1]); 
    }
    return 0;
}
