#define _GNU_SOURCE
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
void display_thread_attr(pthread_attr_t *attr) {
        int ret, a;
        size_t s;
        void *saddr;
        ret = pthread_attr_getguardsize(attr, &s);
        if (ret != 0) {
                printf("pthread_attr_getguardsize error \n");
                return;
        }
        printf("Guard size          = %zu bytes\n", s);

        ret = pthread_attr_getstack(attr, &saddr, &s);
        if (ret != 0 ){
                printf("pthread_attr_getstack error \n");
                return;
        }
        printf("Stack address       = %p\n", saddr);
        printf("Stack size          = %#zx bytes\n", s);
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
        size_t st_size = 16900;
        void *sp;
        int align = getpagesize();
        ret = posix_memalign(&sp, align, st_size);
        if (ret != 0) {
                printf("posix_memalign error\n");
                return -1;
        }

        ret = pthread_attr_init(&attr);
        if (ret != 0) {
                printf("Pthread attribute init error\n");
                return -1;
        }

        ret = pthread_attr_setstack(&attr, sp, st_size);
        if (ret != 0) {
                printf("Pthread attr set stack error\n");
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