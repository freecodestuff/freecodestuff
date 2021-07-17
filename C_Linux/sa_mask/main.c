#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
int f;
void sig_han(int signo, siginfo_t *obj, void *p)
{
        printf("the sighandler :%d \n",signo);
        sleep(5);
        f=1;
        printf("the sighandler returned\n");
}
int main()
{
        struct sigaction act;
        sigset_t sigmask;
        int r;

        printf("pid : %u\n", getpid());
        r = sigemptyset(&sigmask);
        printf("%d\n",r);

        r = sigaddset(&sigmask,4);
        printf("%d\n",r);

        r = sigaddset(&sigmask,3);
        printf("%d\n",r);

        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        act.sa_mask = sigmask;

        if(sigaction(SIGINT,&act,NULL) == -1)
                perror("sigaction");
        printf("test\n");
        for(;;) {
                if(f == 1)
                        break;
        }
        return 0;
}