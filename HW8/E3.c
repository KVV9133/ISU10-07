#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void Input(int arr[],int n)
{

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

}

int* MinArr(int arr[],int n,int min_max[])
{	
	if (n>0)
	{
		min_max[1]=arr[0];
		min_max[0]=1;
		min_max[2]=1;
		min_max[3]=arr[0];
	}
	else 
		return 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>min_max[1])
		{
			min_max[0]=i+1;
			min_max[1]=arr[i];
		}
		if (arr[i]<min_max[3])
		{
			min_max[2]=i+1;
			min_max[3]=arr[i];
		}
	}
	return min_max;
}
 
int main()
{	
	int mass[10];
	int min_max[4];
	Input(mass,10);
	MinArr(mass,10,min_max);
	printf("%d %d %d %d",min_max[0],min_max[1],min_max[2],min_max[3]);
    return 0;
}
 

