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

int* func(int* arr,int *arr2,int* arr3,int n)
{	
	int *ptr = malloc(2 * sizeof(int));
	int q=0,w=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
			arr2[q++]=arr[i];
		else if(arr[i]<0)
			arr3[w++]=arr[i];
	}
	ptr[0]=q;
	ptr[1]=w;
	return ptr;
}

int main()
{	
	int mass[10];
	int mass2[10];
	int mass3[10];
	Input(mass,10);
	int *w=func(mass,mass2,mass3,10);
	PrMass(mass2,w[0]);
	PrMass(mass3,w[1]);
    return 0;
}
 

