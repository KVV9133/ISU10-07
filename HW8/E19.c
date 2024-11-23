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

void PrMass_R(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
		printf("%d ",arr[i]);
	
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


int main()
{	
	int a;
	int mass[20];
	scanf("%d",&a);
	int n=func(mass,a);
	PrMass_R(mass,n);

    return 0;
}
 

