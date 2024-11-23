#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

void Input(int arr[],int n)
{

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

}
void PrMass(int arr[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	
}

int D_Max(int *arr,int n)
{	
	int temp;
	int max=arr[0];
	int s_max=arr[1];
	for(int i=2;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
		if(max>s_max)
		{
			temp=s_max;
			s_max=max;
			max=temp;
		}	
	}
	return max+s_max;
	
}

int main()
{	

	int arr[10];
	Input(arr,10);
	printf("%d ",D_Max(arr,10));

    return 0;
}
 

