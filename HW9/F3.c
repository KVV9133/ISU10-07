#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

int Input(int arr[],int n)
{
	int num,  i=0;
	while(scanf("%d",&num)==1)
		arr[i++]=num;
	return i;
}
void Print(int* arr)
{
	for(int i=0;i<10;i++)
	{	
		if(arr[i]!=0)
			printf("%d %d\n",i, arr[i]);
	}
//	printf("\n");
}
void func(int* arr)
{	
	char c;
	while((c = getchar())!='\n')
		arr[atoi(&c)]++;
	
}


int main()
{	

	int mass[10]={0};
	func(mass);
	Print(mass);

    return 0;
}
 

