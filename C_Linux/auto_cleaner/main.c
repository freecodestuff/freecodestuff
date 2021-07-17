#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int children;

int main()
{
        struct sigaction act;
        pid_t cpid;
        cpid = fork();
        if(cpid == 0){
                printf("Child pid %d\n", getpid());
                exit(1);
        }
        else{
                act.sa_flags = SA_NOCLDWAIT;
                act.sa_handler = SIG_DFL;
                if(sigaction(SIGCHLD,&act,NULL) == -1);
                        perror("sigaction");
                printf("Parent pid %d\n", getpid());
                while(1) {
                        printf("child exit status = %d \n",WEXITSTATUS(children));
                        sleep(1);
                }
        }
        return 0;
}