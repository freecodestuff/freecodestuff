#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int a = 10;
        pid_t pid;
        pid = vfork();
        switch(pid) {
                case -1:
                        perror("vfork");
                        exit(1);
                case 0:
                        printf("child message %d\n",getpid());
                        a = 20;
                        printf("the a value:%d\n",a);
                        exit(1);

                default:
                        printf("parent message %d\n",getpid());
                        printf("the a value:%d\n",a);
                        break;
        }
        return 0;
}