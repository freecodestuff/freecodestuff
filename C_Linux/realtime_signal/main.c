#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
void sig_han(int signo,siginfo_t *obj,void *p)
{
        printf("the sighandler num :%d \n",obj->si_signo);
        switch (obj->si_value.sival_int) {
                case 1:
                        printf("Wide ball\n");
                        break;
                case 2:
                        printf("No Ball, Free Hit\n");
                        break;
                case 3:
                        printf("Out\n");
                        break;
                default:
                        printf("No Signal\n");
                        break;
        }
}
int main()
{
        struct sigaction act;
        union sigval sig;
        int c;
        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGRTMIN,&act,NULL);
        printf("Enter the signal value\n");
        while(1) {
                scanf("%d", &sig.sival_int);
                sigqueue(getpid(),SIGRTMIN, sig);
                sleep(1);
        }
        return 0;
}