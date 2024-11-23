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

int func(int *arr,int n)
{	
	int temp=0,q=0;
	int res=0 ,r=0;
	for(int i=0;i<n-1;i++)
	{	
		temp=arr[i];
		q=0;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]==temp)
				q++;
		}
		if (q>r)
		{
			r=q;
			res=temp;
		}
	}
	return res;
	
}

int main()
{	
	int mass[10];
	Input(mass,10);
	int res=func(mass,10);
	printf("%d",res);

    return 0;
}
 

