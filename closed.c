#include<stdio.h>
#include<stdlib.h>
int a[50];
int hf(int val,int n)
{
	int g=val%n;
	return g;	
}
int clhash(int key,int n)
{
	int i=hf(key,n);
	int placed=0,k,flag=0;
	if(a[i]==-1)
	{
		a[i]=key;
		placed=1;
	}
	else
	{
		for(k=i;k<n;k++)
		{
			if(a[k]==key)
			{
				printf("Value aready exists\n");
				flag=1;
				break;
			}
			else if(a[k]==-1)
			{
				a[k]=key;
				placed=1;
				break;
			}
		}
		if(placed!=1 )
		{
			for(k=0;k<i;k++)
			{
				if(a[k]==key)
				{
					printf("Already exists");
					break;
				}
				else if(a[k]==-1)
				{
					a[k]=key;
					break;
					placed=1;
				}
			}
		}
	}
	return placed;
}
int search(int val,int n)
{
	int i=hf(val,n);
	int k,found=0;
	for(k=i;k<n;k++)
		if(a[k]==val)
		{
			printf("Value found at index %d\n",k);
			found=1;
			break;
		}
	if(found==0)
	{
		for(k=0;k<i;k++)
			if(a[k]==val)
			{
				printf("Value found at index %d",k);
				found=1;
				break;
				
			}
	}

	return found;
}
int main()
{
	int i,ch,n,result,val,skey;
	printf("Enter size :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=-1;
	while(1)
	{
		printf("\n\n1.Enter value\n2.Search\n3.Display\n4.Exit\n\nEnter your choice:  ");
		scanf("%d",&ch);
		if(ch==4)	exit(0);
		else if(ch==1)
		{
			printf("Enter value : ");
			scanf("%d",&val);
			if(search(val,n)==1)
				printf("Value already exist");
			else
			{
				result=clhash(val,n);
				if(result==1)	printf("Placed succesfully\n");
				else printf("Size Overflow");
			}
		}
		else if(ch==2)
		{
			printf("Enter key to search :");
			scanf("%d",&skey);
			if(search(skey,n)==0)
				printf("NOT FOUND\n");
			
		}
		else if(ch==3)
		{
			for(i=0;i<n;i++)
				if(a[i]!=-1)
					printf(" %d",a[i]);
		}
	}
	return 0;
	
}
