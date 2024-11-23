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
void R_V(int arr[],int n)
{	
	int temp_pr=arr[0];
	int temp_next;
	int j=0;
	for(int r=0;r<4;r++)
	{
	for(int i=0;i<n+1;i++)
	{	
		j=i;
		if(j+1>n-1)
			j=i-n;
		
		temp_next=arr[j+1];
		arr[j+1]=temp_pr;
		temp_pr=temp_next;	
	}
	}
}

int main()
{	
	int mass[12];
	Input(mass,12);
	R_V(mass,12);
	PrMass(mass,12);
    return 0;
}
 

