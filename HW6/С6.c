#include <stdio.h>
#include <math.h>
#include <inttypes.h>

unsigned long long int   def(int n)
{	
	return (unsigned long long int)1<<(n-1);
}
int main()
{	
	int a;
	scanf("%d",&a);
	printf("%llu" ,def(a));
	return 0;
}
