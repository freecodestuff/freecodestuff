#include<stdio.h>
#include<pthread.h>
int flag;
int val;
void *threadfun(void *arg)
{
    while(flag != 0);
	__sync_fetch_and_add (&flag,1);
	 	val++;
	__sync_fetch_and_sub (&flag,1);
}

void *threadfun1(void *arg)
{
    while(flag != 0);
    __sync_fetch_and_add (&flag,1);
	printf("the val = %d \n", val);
	__sync_fetch_and_sub (&flag,1);
    
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