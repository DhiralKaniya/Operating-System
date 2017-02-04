#include<stdio.h>
struct round {
	int process;//Specify the process number or Process id
	int at;//Specify the process's arraival time
	int bt;//specify the process's Burst time
	int et;//sepcify the process's execution end time 
};
void main(){
	struct round r1[4];
	int a,b,c,i,qt,total=0,flag,q[20],f=0,r=0,temp,j,context=0;
	//Taking Input from the user for the particular process with arrival time and burst time
	for(i=0;i<4;i++){
		printf("Enter Process %d's details\n",i+1);
		printf("Enter Process number :- ");
		scanf("%d",&a);
		r1[i].process=a;
		printf("Enter Arrival Time of the Process :");
		scanf("%d",&b);
		r1[i].at=b;
		printf("Enter Burst time of the Process : ");
		scanf("%d",&c);
		r1[i].bt=c;
		total+=r1[i].bt;
	}
	//taking quantum time from the user
	printf("Enter a Quantum time ");
	scanf("%d",&qt);
	flag=0;
	for(i=0;i<total;i++)
	{
		//check the process which reach on the i th second and enquee it in queue
		for(j=0;j<4;j++){
			if(i==r1[j].at){
				q[r++]=j;
			}
		}
		//check for the quantum time 
		if((i!=0 && i%qt==0))
		{
			//if previous process burst time is still remain then enquee it in queue
			if(r1[flag].bt>0)
				q[r++]=flag;
			//dequee new process
			flag=q[++f];
			context++;
		}
		else if(r1[flag].bt==0)
		{
			//if quantum time is still remain but process execution or burst time finish in that case dequee other process from the queue
			flag=q[++f];
			context;
		}
		//deduct burst time from the current going process
		r1[flag].bt=r1[flag].bt-1;
		//if the process is completed than print as completed else print as executing for the current second
		if(r1[flag].bt==0){
			printf("process %d is completed\n",r1[flag].process);
			r1[flag].et=i+1;
			
		}
		else{
			printf("Process %d is Executing \n",r1[flag].process);
		}
	}

	printf("total context time is %d\n",context);
	total=0;
	//count average turn arround time
	for(i=0;i<4;i++){
		total+=(r1[i].et-r1[i].at);
	}
	printf("Average tr time is %d",(total/4));
	total=0; 
	//count average waiting time
	for(i=0;i<4;i++)
	{
		total+=(r1[i].et-(r1[i].bt-r1[i].at));
	}
	printf("Average WT time is %d",(total/4));
}