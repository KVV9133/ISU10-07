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
void InverHalf(int arr[],int start, int stop)
{	
	int temp=0;
	for(int i=start,j=stop-1;i<(stop+start)/2;i++,j--)
	{	
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

int main()
{	
	int mass[10];
	Input(mass,10);
	InverHalf(mass,0,5);
	InverHalf(mass,5,10);
	PrMass(mass,10);
    return 0;
}
 

