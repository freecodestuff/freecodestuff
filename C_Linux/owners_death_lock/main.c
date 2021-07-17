#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
struct a{
	int a;
	int b;
}obj;

sem_t flag;


void *threadfun(void *arg)
{

	sem_wait(&flag);


	obj.a = 10;
	obj.b = 20;

	pthread_exit(NULL);
	sem_post(&flag);
	return NULL;	
}

void *threadfun1(void *arg)
{
	sem_wait(&flag);

	printf("the a value %d\n",obj.a);
	printf("the b value %d\n",obj.b);

	sem_post(&flag);

	return NULL;	
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	void *res;

	sem_init(&flag, 0, 1);
	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun1,NULL);

	pthread_join(t1,&res);
	pthread_join(t2,&res);


	return 0;
}	