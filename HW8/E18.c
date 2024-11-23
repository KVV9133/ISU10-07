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

void func(int a)
{	
	int temp=0;
	for(int j=2;j<10;j++)
	{	
		temp=0;
		for(int i=2;i<a+1;i++)
		if(i%j==0)
			temp++;
		printf("%d %d\n",j,temp);
	}
}


int main()
{	
	int a;
	scanf("%d",&a);
	func(a);

    return 0;
}
 

