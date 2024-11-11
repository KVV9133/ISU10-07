#include <stdio.h>
#include <math.h>

int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	while(a!=0&&b!=0)
	{
		if (a>b)
			a=a%b;
		else
			b=b%a;
	}
	printf("%d",a+b);
	return 0;
}