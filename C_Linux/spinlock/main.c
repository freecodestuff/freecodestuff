#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
pthread_spinlock_t lock;

void *threadfun1(void *arg)
{

        printf("thread 1 started\n");
        pthread_spin_lock(&lock);
        sleep(4);
        printf("thread1 acquired lock\n");
        pthread_spin_unlock(&lock);
        printf("thread 1 released lock object\n");
        return NULL;
}

void *threadfun2(void *arg)
{
        sleep(1);
        printf("thread 2 started \n");
        pthread_spin_unlock(&lock);
         
        pthread_spin_lock(&lock);
        printf("thread 2 acquired lock\n");
        pthread_spin_unlock(&lock);
        printf("thread 2 release lock object\n");
        return NULL;
}

int main()
{
        pthread_t t1, t2;
        void *res;
        
	    pthread_create(&t1,NULL,threadfun1,NULL);
        pthread_create(&t2,NULL,threadfun2,NULL);

        pthread_join(t1, &res);
        pthread_join(t2, &res);

        return 0;
}
