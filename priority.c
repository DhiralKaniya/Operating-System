#include<stdio.h>
struct process {
	int pno;
	int at;
	int bt;
	int pr;
	int et;
}
void main(){
	struct process p[4];
	int i,j,bt,at,pr,pno;
	//taking input from the users.
	for(i=0;i<4;i++){
		printf("Enter the Process Number :-");
		scanf("%d",&pno);
		printf("Enter the Process Arrival Time :-");
		scanf("%d",&at);
		printf("Enter the Process Burst Time :-");
		scanf("%d",&bt);
		printf("Enter the Priority :-");
		scanf("%d",&pr);
		p[i].pno=pno;
		p[i].bt=bt;
	}
}