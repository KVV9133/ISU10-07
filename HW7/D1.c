#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int n)
{
	if (n>1)
		func(n-1);
	printf("%d ",n);
}

int main()
{
	int n;
	scanf("%d",&n);
	func(n);
	
	return 0;	
}
