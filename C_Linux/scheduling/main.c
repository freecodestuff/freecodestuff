#define _GNU_SOURCE
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
void display_thread_attr(pthread_attr_t *attr) {
        int ret, a;
        struct sched_param p;
        ret = pthread_attr_getschedpolicy(attr, &a);
        if (ret != 0) {
                printf("pthread_attr_getschedpolicy error \n");
                return;
        }
        printf("Scheduling policy   = %s\n",
                        (a == SCHED_OTHER) ? "SCHED_OTHER" :
                        (a == SCHED_FIFO)  ? "SCHED_FIFO" :
                        (a == SCHED_RR)    ? "SCHED_RR" :
                        "???");
        ret = pthread_attr_getschedparam(attr, &p);
        if (ret != 0) {
                printf("pthread_attr_getschedparam error \n");
                return;
        }
        printf("Scheduling priority = %d\n", p.sched_priority);
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

        ret = pthread_join(th, NULL);
        if (ret != 0) {
                printf("pthread_join error \n");
                return -1;
        }

        return 0;
}