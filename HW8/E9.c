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
	for(int i=0;i<n+1;i++)
	{	
		j=i;
		if(j+1>9)
			j=i-10;
		
		temp_next=arr[j+1];
		arr[j+1]=temp_pr;
		temp_pr=temp_next;

		
	}
}

int main()
{	
	int mass[10];
	Input(mass,10);
	R_V(mass,10);
	PrMass(mass,10);
    return 0;
}
 

