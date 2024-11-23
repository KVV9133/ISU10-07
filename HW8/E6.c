#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void Input(int arr[],int n)
{

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

}

float Sr(int arr[],int n)
{	
	int res=0;
	for(int i=0;i<n;i++)
		res+=arr[i];
	return (float)res/n;
}

int main()
{	
	int mass[12];
	Input(mass,12);
	printf("%.2f",Sr(mass,12));
    return 0;
}
 

