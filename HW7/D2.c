#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int func(int n)
{
	if (n==1)
		return 1;
	return n+(func(n-1));
	
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",func(n));
	
	return 0;	
}