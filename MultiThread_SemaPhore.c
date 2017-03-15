#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
//Please reference this link :- https://jlmedina123.wordpress.com/2013/05/03/pthreads-with-mutex-and-//semaphores/
int count = 0;
sem_t test;

void *printfunct(void *num){
	int i;
	sem_wait(&test);
	for(i=0;i<10000;i++)
	{
		count++;
		printf("%d->%ld||",count,(long)num);
	}
	sem_post(&test);
}

int main(){
	sem_init(&test,0,2);
	pthread_t th1,th2;
	pthread_create(&th1,NULL,&printfunct,(void *)1);
	pthread_create(&th2,NULL,&printfunct,(void *)2);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	sem_destroy(&test);
	
}
