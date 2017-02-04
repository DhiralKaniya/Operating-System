#include<stdio.h>
struct pro
{
	int process;
	int bt;
	int at;
	int et;
};
void main(){
	struct pro pr[4];
	int pre,bt,at,i,j,total=0,block[4],flag=0,min,context=0;
	for(i=0;i<4;i++){
		printf("Enter Process Number :- ");
		scanf("%d",&pre);
		printf("Enter Arrival Time :- ");
		scanf("%d",&at);
		printf("Enter Burst Time :- ");
		scanf("%d",&bt);
		pr[i].process = pre;
		pr[i].at = at;
		pr[i].bt = bt;
		total+=pr[i].bt;	
		
	}
	//printf("%d->",total);
	for(i=0;i<total;i++){
		flag=0;
		//take process which arrival time is lesser than or equal to current time and process still having burst time
		for(j=0;j<4;j++){
			if(pr[j].at <= i && pr[j].bt > 0){
				block[flag]=j;
				flag++;
			}
		}
		min=block[0];
		//if process found in block 
		if(flag > 1)//if in the block more than one process is founded
		{
			for(j=0;j<flag;j++){
				if(pr[min].bt > pr[block[j]].bt){
					min = block[j];
					//counter for the context Switching
					context++;

				}
			}
		}

		//now deduct the process burst time
		pr[min].bt-=1;

		//check process is completed or not
		if(pr[min].bt==0){
			printf("Process %d is completed successfully at the time of %d\n",pr[min].process,i+1);
			pr[min].et = i+1;
		}
		
	}
	printf("\nContext Switching time is %d\n",context);
	
	total=0;
	//counting the turn arround time.
	for(i=0i;i<4;i++)
	{
		total+=(pr[i].et-pr[i].at);
	}
	printf("\nAverage Turn Arround time is = %d",(total/4));
	total=0;
	//counting the waiting time
	for(i=0;i<4;i++){
		total+=(pr[i].et-(pr[i].bt - pr[i].at));
	}
	printf("\nAverage Waiting time is = %d",(total/4));
}

