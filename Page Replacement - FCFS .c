#include<stdio.h>
void main()
{
	int arr[10],farr[3];
	int frame,i,j,pf=0,flg,count;

	printf("Enter scheduling for the 5 processes");
	for(i=0;i<10;i++){	
		scanf("%d",&arr[i]);
	}

	printf("Enter Frame Size :- ");
	scanf("%d",&frame);


	for(i=0;i<frame;i++){
		farr[i]	= arr[i];	
		printf("%d\n",farr[i]);
	}

	pf=frame;
	count=frame;

	for(i=frame;i<10;i++){
		flg=0;
		for(j=0;j<frame;j++){
			if(arr[i]==farr[j]){
				flg=1;
				break;
			}
		}
		if(flg==0)
		{
			if(count==frame)
				count=0;
			farr[count]=arr[i];
			printf("%d",farr[count]);
			pf++;
			count++;
		}
		printf("\n");
	}
	printf("%d",pf);

}
