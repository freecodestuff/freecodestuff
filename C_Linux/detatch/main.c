#define _GNU_SOURCE
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
void display_thread_attr(pthread_attr_t *attr) {
        int ret, a;
        ret = pthread_attr_getdetachstate(attr, &a);
        if (ret != 0) {
                printf("pthread_attr_getdetachstate error \n");
                return;
        }
        printf("Detach state        = %s\n",
                        (a == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :
                        (a == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :
                        "???");
}
static void *threadfun(void *arg)
{
        pthread_attr_t gattr;
        int ret;

        char *s=(char *)arg;
        ret = pthread_getattr_np(pthread_self(), &gattr);
        if (ret != 0) {
                printf("pthread_getattr_np error \n");
                return (void *)-1;
        }
        display_thread_attr(&gattr);
        exit(1);
}
int main()
{
        pthread_t th;
        pthread_attr_t attr;
        int ret;
        ret = pthread_attr_init(&attr);
        if (ret != 0) {
                printf("Pthread attribute init error\n");
                return -1;
        }

        ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        if (ret != 0) {
                printf("Pthread attribute set detach error\n");
                return -1;
        }

        ret = pthread_create(&th,&attr,&threadfun,NULL);
        if (ret != 0) {
                printf("pthread create error\n");
                return -1;
        }

        ret = pthread_attr_destroy(&attr);
        if (ret != 0) {
                printf("pthread attr destroy error\n");
                return -1;
        }
        pause();
        return 0;
}