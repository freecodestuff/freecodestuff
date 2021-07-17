#include<stdio.h>
#include<signal.h>
#include<string.h>
#include <unistd.h>
int f;
void sig_han(int signo)
{
        printf("the sighandler :%d \n",signo);
        printf("the pid :%d\n",getpid());
        f = 1;
}
int main()
{
        struct sigaction act;
        memset(&act,0,sizeof(act));
        act.sa_handler = sig_han;
        sigaction(2,&act,NULL);
        while(1) {
                if(f == 1)
                        break;
                printf("test\n");
                sleep(1);
        }
        return 0;
}