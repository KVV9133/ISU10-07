#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

void SwapArr(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int func(int* arr, int n)
{	
	int i=0;
	while(n)
	{
		arr[i++]=n%10;
		n/=10;
	}
	return i;
}
void SortC(int* arr, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[j-1]<arr[j])
			SwapArr(arr,j-1,j);
		}
		
	}
	
	
}
int InM(int* arr,int n)
{	
	int res=0;
	int st=n-1;
	for(int i=0;i<n;i++)
		res+=arr[i]*pow(10,st--);
	return res;
}

int main()
{	
	int a;
	int mass[20];
	scanf("%d",&a);
	int n=func(mass,a);
	SortC(mass,n);
	printf("%d",InM(mass,n));

    return 0;
}
 

