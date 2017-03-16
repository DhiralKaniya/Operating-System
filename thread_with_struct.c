#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
int g=0;
struct t_test{
	int int_value[2];
	long thread_id[2];

}test;
void *printThread(void *tid){
	test.thread_id[g]=pthread_self();
	test.int_value[g]=g;
	g++;
}
int main(){
	pthread_t th1;
	pthread_t th2;
	
	//Set concurrency of thread
	pthread_setconcurrency(2);
	
	//create thread
	pthread_create(&th1,NULL,printThread,(void *)1);
	pthread_create(&th2,NULL,printThread,(void *)1);

	//wait untill both threads execution has been finish
	pthread_join(th1,NULL);	
	pthread_join(th2,NULL);

	//printing value after threading
	printf("1st thread id is %ld and thread's value -> %d\n",test.thread_id[0],test.int_value[0]);
	printf("2nd thread id is %ld and thread's value -> %d\n",test.thread_id[1],test.int_value[1]);

	exit(0);
}
