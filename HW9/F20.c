#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

int Input(int arr[])
{
	int num,  i=0;
	while(scanf("%d",&num)==1)
		arr[i++]=num;
	return i;
}

void Print(int* arr,int n)
{	
	
	for(int i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int Even_Odd(int* arr)
{
	int even=0;
	for(int i=0;i<10;i++)
		if(arr[i]%2==0)
			even++;
	return even>5?1:0;
}
int Zam_Odd(int n)
{	
	int res=1;
	int temp;
	while(n)
	{	
		temp=n%10;
		if(temp%2==1)
			res*=temp;
		n/=10;
	}
	return res;
}
int Zam_Even_Odd(int n,int e_o)
{	
	int res=1;
	int temp;
	while(n)
	{	
		temp=n%10;
		if(temp%2==e_o)
			res*=temp;
		n/=10;
	}
	return res;
}
void func(int* arr,int e_o)
{
	for(int i=0;i<10;i++)
		if(arr[i]%2==e_o)
			arr[i]=Zam_Even_Odd(arr[i],e_o);
}




int main()
{	
	int arr[10];
	Input(arr);
	int ev=Even_Odd(arr);
	func(arr,ev);
	Print(arr,10);
    return 0;
}
 

