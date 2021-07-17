#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
int f;
void sig_han(int signo,siginfo_t *obj,void *p)
{
        printf("the sighandler num :%d \n",obj->si_signo);
        printf("the sigcode :%d \n",obj->si_code);
        f=1;
}
int main()
{
        struct sigaction act;
        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        act.sa_flags = SA_SIGINFO;
        sigaction(2,&act,NULL);
        while(1) {
                if(f == 1)
                        break;
                printf("test\n");
                sleep(1);
        }
        return 0;
}