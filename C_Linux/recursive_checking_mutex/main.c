#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>


pthread_mutex_t mutex;

void *threadfun(void *arg)
{
	printf("thread1 started\n");
	pthread_mutex_lock(&mutex);
	if(!pthread_mutex_lock(&mutex))
		printf("thread error\n");
	printf("thread1 after locking\n");
	printf("test\n");

	pthread_mutex_unlock(&mutex);
	return NULL;	
}


int main()
{
	pthread_t t1;
	pthread_mutexattr_t attr;
	
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex,&attr);
	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_join(t1,NULL);
	
	return 0;
}	
