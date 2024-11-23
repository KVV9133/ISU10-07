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
	return a%10;
}
void Sort(int arr[],int n)
{	

	for(int i=0;i<n;i++)
	{	

		for(int j=n-1;j>i;j--)
		{
			if(LC(arr[j-1])>LC(arr[j]))
			{
				swapArr(arr,j-1,j);


			}
		}

	}	
}

int main()
{	
	int mass[10];
	Input(mass,10);
	Sort(mass,10);
	PrMass(mass,10);
    return 0;
}
 

