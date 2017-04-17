#include<stdio.h>
void main()
{

	int arr[10],farr[4];
	int flag1,flag2,i,j,k,pf=0,fsize,v,count=0;

	printf("Enter page fault for 5 processes\n");
	for(i=0;i<10;i++)	
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter No of page size :- ");
	scanf("%d",&fsize);
	
	for(i=0;i<fsize;i++)
	{
		farr[i]=-1;
	}
	for(i=0;i<10;i++)
	{
		flag1=0;
		flag2=0;
		for(j=0;j<fsize;j++)
		{
			if(farr[j]==-1)
			{
				flag1=1;
				farr[j]=arr[i];
				pf++;				
				printf("%d\n",farr[j]);
				break;
			}
		}

		if(flag1==0){
					
			for(j=0;j<fsize;j++)
			{
				if(farr[j]==arr[i])
				{
					flag2=1;
					break;
				}
			}			
		}
	
		if(flag1==0 && flag2==0)
		{
			v=0;
			count=0;
			for(j=i-1;j>=0;j--){
				for(k=0;k<fsize;k++)
				{					
					if(arr[j]==farr[k])
					{
						if(count==fsize-1)
						{
							count=k;
							v=1;
							break;
						}		
						count++;
					}
				}			
				if(v==1)
				{
					farr[count]=arr[i];
					pf++;
					count=0;
					v=0;
					break;
				}
					
			}
		}
		printf("%d %d %d %d \n",farr[0],farr[1],farr[2],farr[3]);
	}
	printf("%d",pf);
}
