#include <stdio.h>
#include <math.h>

int fx(int x)
{	
	if (x>=-2 && x<2)
		return x*x;
	else if (x>=2)
		return x*x+4*x+5;
	else if (x<-2)
		return 4;
	return 0;
}
int main()
{	int max=0;
	int a;
	while(scanf("%d ",&a) && a!=0)
	{
	if 	(fx(a)>max)
		max=fx(a);
	}
	printf("%d",max);
		
	return 0;
}
