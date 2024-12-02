#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

int Input(int arr[])
{
	int num,  i=0;
	while(scanf("%d",&num)==1 && num!=0)
		arr[i++]=num;
	return i;
}
void Print(int* arr,int n)
{	
	
	for(int i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int func(int* arr, int n)
{	
	int sum=0,min=1<<30,max=1<<31;
	for(int i=0;i<n;i++)
	{	
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
		sum+=arr[i];
	}
	return (n+1)*(min+max)/2-sum;
	
}

int main()
{	


	int arr[1500];
	int n=Input(arr);
	printf("%d",func(arr, n));


    return 0;
}
 

