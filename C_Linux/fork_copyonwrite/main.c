#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
        pid_t pid;
        int a = 10;
        pid = fork();
        switch(pid) {
                case -1:
                        perror("fork");
                        exit(1);

                case 0:
                        printf("child pid %d\n",getpid());
                        a = 20;
                        printf("child: a  %d\n",a);
                        exit(1);
                default:
                        wait(NULL);

                        printf("parent pid %d\n",getpid());
                        printf("parent: a %d\n",a);
                        break;
        }
        return 0;
}