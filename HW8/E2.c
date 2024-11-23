#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void Input(int arr[],int n)
{

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

}

int MinArr(int arr[],int n)
{	
	int min;
	if (n>0)
		min=arr[0];
	else 
		return 0;
	for(int i=0;i<n;i++)
		if(arr[i]<min)
			min=arr[i];
	return min;
}
 
int main()
{	
	int mass[5];
	Input(mass,5);
	printf("%d",MinArr(mass,5));
    return 0;
}
 

