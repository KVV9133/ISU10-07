#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int n,int a)
{	
	if(n<a)
		return;
	else if (n%a==0)
	{	
		printf("%d ",a);
		func(n/a,a);
	}
	else
		func(n,a+1);
}
 
int main()
{	
	int n;
	scanf("%d",&n);
	func(n,2);
    return 0;
}
 

