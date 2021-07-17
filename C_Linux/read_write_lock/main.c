#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

struct data {
	int n;
	char name[10];
}obj;

void *writethread(void *arg)
{
    printf("write thread started\n");
    pthread_rwlock_wrlock(&rwlock);
    strcpy(obj.name, "hi");
	obj.n = 1;
    pthread_rwlock_unlock(&rwlock);
	printf("writing done\n");
    return NULL;
}

void *read1thread(void *arg)
{
	sleep(3);
    printf("read 1 thread started \n");
    pthread_rwlock_rdlock(&rwlock);
	printf("%s\n", obj.name);
	printf("%d\n", obj.n); 
	pthread_rwlock_unlock(&rwlock);
    printf("thread 2 release mutex object\n");
    return NULL;
}

void *read2thread(void *arg)
{       
    sleep(5);
    printf("read 2 thread started \n");
    pthread_rwlock_rdlock(&rwlock);
    printf("%s\n", obj.name);
    printf("%d\n", obj.n);
    pthread_rwlock_unlock(&rwlock);
    printf("thread 3 release mutex object\n");
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    void *res;

    pthread_create(&t1,NULL,writethread,NULL);
    pthread_create(&t2,NULL,read1thread,NULL);
    pthread_create(&t3,NULL,read2thread,NULL);

	pthread_join(t1, &res);
    pthread_join(t2, &res);
    pthread_join(t3, &res);
	
	return 0;
}
