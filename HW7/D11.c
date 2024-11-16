#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int func(int n)
{	
	if (n==0)
		return 0;
	return n%2+func(n/2);
}
 
int main()
{	
	int n;
	scanf("%d",&n);
	printf("%d ",func(n));
    return 0;
}
 

