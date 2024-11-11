#include <stdio.h>
#include <math.h>
#include <math.h>

int main()
{	
	int a;
	scanf("%d",&a);
	int sum=0;
	while(a)
	{
		sum+=a%10;
		a/=10;
	}
	if (sum==10)
		printf("YES");
	else
		printf("NO");
	return 0;
}