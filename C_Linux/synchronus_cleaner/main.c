#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
        pid_t pid;
        int exit_stat;
        int tri_pid;
        pid = fork();

        switch(pid){
                case 1:
                        perror("fork");
                        exit(1);
                case 0:
                        printf("In child :%u\n",getpid());
                        exit(1);
                default:
                        tri_pid = wait(&exit_stat);
                        if(tri_pid < 0)
                                perror("wait");
                        printf("in parent :%u\n",getpid());
                        printf("exit state of child : %d\n",WEXITSTATUS(exit_stat));
                        break;
        }
        return 0;
}