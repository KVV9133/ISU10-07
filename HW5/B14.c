#include <stdio.h>
#include <math.h>

int main()
{	
	int a;
	int count=0;
	while(scanf("%d",&a) && a!=0)
		count++;
	printf("%d",count);

	return 0;
}