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
void swap_negmax_last(int size, int a[])
{	
	int min=1<<31;
	int ind=0;
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(a[i]<0 && a[i]>min)
			{	
				flag=1;
				min=a[i];
				ind=i;
			}
	}
	if (flag)
	{
		int temp=min;
		a[ind]=a[size-1];
		a[size-1]=temp;
	}
}

int main()
{	


	int arr[1500];
	int n=Input(arr);
	swap_negmax_last(n,arr);
	Print(arr,n);

    return 0;
}
 

