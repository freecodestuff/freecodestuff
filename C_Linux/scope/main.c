#define _GNU_SOURCE
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
void display_thread_attr(pthread_attr_t *attr) {
        int ret, a;
        ret = pthread_attr_getscope(attr, &a);
        if (ret != 0) {
                printf("pthread_attr_getscope error \n");
                return;
        }
        printf("Scope         = %s\n",
                        (a == PTHREAD_SCOPE_SYSTEM) ? "PTHREAD_SCOPE_SYSTEM" :
                        (a == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS" :
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

        ret = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
        if (ret != 0) {
                printf("Pthread attribute set scope error %s\n", strerror(errno));
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