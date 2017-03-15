#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int count = 0;
void *printfunct(void *num){
	int i;
	for(i=0;i<100;i++)
	{
		count++;
		printf("%d->%ld\n",count,(long)num);
	}
	
}

int main(){

	pthread_t th1,th2;
	pthread_create(&th1,NULL,&printfunct,(void *)1);
	pthread_create(&th2,NULL,&printfunct,(void *)2);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	
}
