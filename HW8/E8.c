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
	int mass[12];
	Input(mass,12);
	InverHalf(mass,0,4);
	InverHalf(mass,4,8);
	InverHalf(mass,8,12);
	PrMass(mass,12);
    return 0;
}
 

