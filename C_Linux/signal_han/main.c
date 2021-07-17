#include<stdio.h>
#include<signal.h>
#include <unistd.h>
int f;
void sig_han(int signo)
{
        printf("signal handler:%d\n",signo);
        f = 1;
}
int main()
{
        signal(2,sig_han);
        while(1) {
                if(f == 1)
                        break;
                printf("test\n");
                sleep(1);
        }
        return 0;
}