#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
void main()
{
	int i,q[10],n,limit,head,seek=0;

	printf("Enter Header :- ");
	scanf("%d",&head);	
	q[0]=head;

	printf("Enter Number of Elements :- ");
	scanf("%d",&n);

	printf("Enter Elements :- ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&q[i]);
	}
		
	for(i=0;i<n;i++)
	{
		seek+=abs(q[i]-q[i+1]);
	}		
	printf("%d",seek);
}
