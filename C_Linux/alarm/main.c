#include<stdio.h>
#include<signal.h>
#include <unistd.h>
void sig_han(int signo)
{
        printf("signal handler:%d\n",signo);
}
int main()
{
        signal(SIGALRM,sig_han);
        alarm(2);
        while(1) {
                printf("test\n");
                sleep(1);
        }
        return 0;
}