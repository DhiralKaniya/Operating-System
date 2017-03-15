#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//please reference this url :- http://www.thegeekstuff.com/2012/05/c-mutex-examples/?refcom;

int count = 0;
pthread_mutex_t lock;
pthread_t th1,th2,th3;

void *printfunct(void *num){
	pthread_mutex_lock(&lock);
	int i;

	for(i=0;i<55000;i++)
	{
		count++;
		printf("%d->%ld||",count,(long)num);
	}

	pthread_mutex_unlock(&lock);

}

void main(){

		

	//Mutext initialization
	pthread_mutex_init(&lock,NULL);

	//thread created
	pthread_create(&th1,NULL,printfunct,(void *)1);
	pthread_create(&th2,NULL,printfunct,(void *)2);
	pthread_create(&th3,NULL,printfunct,(void *)3);

	//Join both thread
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
		
	//mutext destroy
	pthread_mutex_destroy(&lock);
}
