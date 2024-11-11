#include <stdio.h>
#include <math.h>

int main()
{	
	int a;
	scanf("%d",&a);
	int even=0,odd=0;
	int temp=0;
	while(a)
	{
		temp=a%10;
		if (temp&1)
			odd++;
		else
			even++;
		a/=10;
	}
	printf("%d %d",even,odd);

	return 0;
}