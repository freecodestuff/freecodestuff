#include<stdio.h>
#include<pthread.h>
#include<string.h>
static void *threadfun(void *arg)
{
        char *s=(char *)arg;
        printf("%s\n",s);
        return (void *)strlen(s);
}
int main()
{
        pthread_t t1;
        void *res;
        int ret;
        ret = pthread_create(&t1,NULL,threadfun,"hello world");
        if (ret != 0) {
                printf("pthread create error\n");
                return -1;
        }
        ret = pthread_join(t1,&res);
        if (ret != 0) {
                printf("pthread join error\n");
                return -1;
        }

        printf("thread returned %ld \n",(long)res);

        return 0;
}