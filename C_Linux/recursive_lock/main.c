#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>

sem_t flag;

void fun();
void *threadfun(void *arg)
{

	sem_wait(&flag);
	printf("in thread\n");
	fun();
	sem_post(&flag);
	return NULL;	
}

void fun()
{
	printf("function\n");
	sem_wait(&flag);
	printf("wait\n");
	sem_post(&flag);
}

int main()
{
	pthread_t t1;
	void *res;

	sem_init(&flag, 0, 1);
	pthread_create(&t1,NULL,threadfun,NULL);

	pthread_join(t1,&res);


	return 0;
}	


