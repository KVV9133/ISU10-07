#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int a,int b)
{	
	if(a==b)
	{
		printf("%d ",b);
		return;
	}
	if(a>b)
	{
		printf("%d ",a);
		func(a-1,b);
	}
	else
	{
		printf("%d ",a);
		func(a+1,b);
	}	
}
 
int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	func(a,b);
    return 0;
}
 

