#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int def(int n)
{	
	if (n==1)
		return 1;
	return n*def(n-1);

};
int main()
{	
	int n;
	scanf("%d",&n);
	printf("%d",def(n));
	return 0;
}
