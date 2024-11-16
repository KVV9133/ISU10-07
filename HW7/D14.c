#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(void)
{	
	int a;
	scanf("%d",&a);
	if (a==0)
		return;
	else if((a&1)!=0)
	{
		printf("%d ",a);
		func();
	}
	else
		func();
}
 
int main()
{	
	func();
    return 0;
}
 

