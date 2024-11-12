#include <stdio.h>
#include <math.h>

int abs1(int a)
{
	return a>0?a:-a;
}
int main()
{	
	int a;
	scanf("%d",&a);
	printf("%d",abs1(a));
	return 0;
}
