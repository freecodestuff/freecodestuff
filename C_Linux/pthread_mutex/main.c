#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
struct a{
	int a;
	int b;
}obj;

pthread_mutex_t mut= PTHREAD_MUTEX_INITIALIZER;

void *threadfun(void *arg)
{
	pthread_mutex_lock(&mut);
	obj.a = 10;
	obj.b = 20;
	pthread_mutex_unlock(&mut);
	return NULL;	
}

void *threadfun1(void *arg)
{

	pthread_mutex_lock(&mut);
	printf("the a value %d\n",obj.a);
	printf("the b value %d\n",obj.b);
	pthread_mutex_unlock(&mut);
	return NULL;	
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	void *res;

	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun1,NULL);

	pthread_join(t1,&res);
	pthread_join(t2,&res);

	return 0;
}