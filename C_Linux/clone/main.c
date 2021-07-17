#define _GNU_SOURCE
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define STACK_SIZE 8192
int child()
{
        printf("Child pid : %d\n", getpid());
        return 0;
}

int main()
{
        void *child1;
        int exit_stat;
        child1 = malloc(STACK_SIZE);
        if(!child1) {
                perror("Malloc Failed");
                return -1;
        }
        if(clone(&child,(char *)child1 + STACK_SIZE,CLONE_VM|SIGCHLD,0) < 0) {
                perror("Clone Failed");
                return -1;
        }
        wait(&exit_stat);
        printf("Parent pid : %d\n", getpid());
        free(child1);
        return 0;

}