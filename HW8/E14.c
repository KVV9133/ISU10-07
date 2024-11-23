#include <stdio.h>
#include <math.h>
#include <inttypes.h>

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

int findDubl(int* arr,int *arr2,int n)
{
	int q=0;
	int temp=0;
	for(int i=0;i<n;i++)
	{
		temp=arr[i];
		if(q>0 && FD(arr2,temp,q))
			continue;
		for(int j=i+1;j<n;j++)
		{
			if (temp==arr[j])
			{
				arr2[q++]=temp;
				break;
			}
		}
		
		
	}
	return q;
	
}

int main()
{	
	int mass[10];
	int mass2[10];
	Input(mass,10);
	int n=findDubl(mass,mass2,10);
	PrMass(mass2,n);
    return 0;
}
 

