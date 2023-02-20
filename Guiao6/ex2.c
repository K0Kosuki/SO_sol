#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
char fd;
fd=open("fifo", O_WRONLY);
char buffer[1024];
int n;



while ((n=read(0,buffer,sizeof(buffer)))> 0)
{
  write(fd,buffer,n);
}

return 0;
}
