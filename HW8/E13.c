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
void swapArr(int* arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int LC(int a)
{	
	if ((a/10)%10==0)
		return 1;
	else
		return 0;
}
int func(int *arr,int* arr2,int n)
{
	int j=0;
	for(int i=0;i<n;i++)
		if (LC(arr[i]))
			arr2[j++]=arr[i];
	return j;
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
 

