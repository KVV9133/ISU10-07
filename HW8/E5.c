#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void Input(int arr[],int n)
{

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

}

int Summ(int arr[],int n)
{	
	int res=0;
	for(int i=0;i<n;i++)
		if(arr[i]>0)
			res+=arr[i];
	return res;
}

int main()
{	
	int mass[10];
	Input(mass,10);
	printf("%d",Summ(mass,10));
     return 0;
} 

