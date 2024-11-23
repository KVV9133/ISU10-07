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
int FD(int *arr,int a,int n)
{
	for(int i=0;i<n;i++)
		if(arr[i]==a)
			return 1;
	return 0;
}

int func(int *arr,int *arr2,int n)
{	
	int temp=0;
	int flag=0;
	int q=0;
	for(int i=0;i<n;i++)
	{	
		flag=0;
		temp=arr[i];
		if (FD(arr,temp,i))
			continue;
		for(int j=i+1;j<n;j++)
		{	
			if(temp==arr[j])
			{
				flag=1;
				break;
			}
		}
		if (!flag)
			arr2[q++]=temp;
	}
	return q;
}

int main()
{	
	int mass[10];
	int mass2[10];
	Input(mass,10);
	int n=func(mass,mass2,10);
	PrMass(mass2,n);

    return 0;
}
 

