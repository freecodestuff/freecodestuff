#include<stdio.h>
#include<signal.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
static int pipe_fd[2];
void sig_han(int signo,siginfo_t *obj,void *p)
{
        printf("the sighandler :%d \n",signo);
        write(pipe_fd[1],"welcome",8);
}
int main()
{
        int fd;
        char rbuf[8];
        struct sigaction act;
        if (pipe(pipe_fd) < 0) {
                perror("pipe");
        }
        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        act.sa_flags = SA_RESTART;
        if(sigaction(2,&act,NULL) == -1)
                perror("sigaction");
        printf("test\n");
        memset(rbuf, 0, 8);
        read(pipe_fd[0],rbuf,sizeof(rbuf));
        printf("the read :%s %ld\n",rbuf, strlen(rbuf));
        return 0;
}