#include<pthread.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

void *printThreadId(void *tid){
	long thid = (long) tid;
	printf("%d\n",thid);
	long j = (long)pthread_self();
	printf("%ld\n",j);
	return NULL;
}
int main()
{
	long i;
	pthread_t th;
	printf("Before Thread\n");
	for(i=0;i<3;i++)
	{
		pthread_create(&th,NULL,printThreadId,(void *)i);
		pthread_join(th,NULL);			
	}
	
	printf("After Thread\n");	
	exit(0);
}
