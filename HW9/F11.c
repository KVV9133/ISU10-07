#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

int Input(int arr[])
{
	int num,  i=0;
	while(scanf("%d",&num)==1)
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
void func(int* arr, int n)
{	
	int min1=arr[0];
	int min2=arr[1];
	int ind1=0,ind2=1;
	for(int i=2;i<n;i++)
	{	
		
		if(min1>arr[i])
		{
			min1=arr[i];
			ind1=i;
		}
		if(min1<min2)
		{
			int temp=min2;
			int temp_ind=ind2;
			min2=min1;
			min1=temp;
			ind2=ind1;
			ind1=temp_ind;
		}
	
	}
	ind1<ind2?printf("%d %d",ind1,ind2):printf("%d %d",ind2,ind1);
}

int main()
{	


	int arr[30];
	Input(arr);
	func(arr,30);

    return 0;
}
 

