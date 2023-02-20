#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fbv[2], fbm[2];
    pid_t pidv = fork();
    
    int n;
    char buf[256];
    pipe(fbm);
    pipe(fbv);

    if(pidv == 0){
        close(fbv[1]);
        dup2(fbv[1],0);
        close(fbv[0]);
         execlp("gzip", "gzip", "-c", "- > V.gz", (char ) NULL);
    }
    else{
        pid_t pidm = fork();
        if (pidm ==0)
        {
            close(fbm[1]);
            

        }
        

    }
    
}