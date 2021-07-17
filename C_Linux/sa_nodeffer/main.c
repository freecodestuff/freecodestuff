#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
int f;
void sig_han(int signo,siginfo_t *obj,void *p)
{
        printf("the sighandler :%d \n",signo);
        sleep(5);
        f = 1;
        printf("exit sighandler\n");
}
int main()
{
        struct sigaction act;
        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        act.sa_flags = SA_NODEFER;
        if(sigaction(2,&act,NULL) == -1)
                perror("sigaction");
        while(1) {
                if(f == 1)
                        break;
                printf("test\n");
                sleep(1);
        }
        return 0;
}