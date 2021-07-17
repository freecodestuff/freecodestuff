#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        pid_t pid;

        pid = fork();

        switch(pid){
                case 1:
                        perror("fork");
                        exit(1);

                case 0:
                        printf("child pid :%u\n",getpid());
                        exit(1);

                default:
                        printf("parent pid :%u\n",getpid());
                        break;

        }

        return 0;
}