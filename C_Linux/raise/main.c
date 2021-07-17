#include<stdio.h>
#include<signal.h>
#include <unistd.h>
void sig_han(int signo)
{
        printf("signal handler:%d\n",signo);
}
int main()
{
        signal(2,sig_han);
        printf("test\n");
        raise(2);
        return 0;
}