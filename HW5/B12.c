#include <stdio.h>
#include <math.h>

int main()
{	
	int a;
	scanf("%d",&a);
	int min=10,max=0;
	int temp=0;
	while(a)
	{
		temp=a%10;
		if (temp<min)
			min=temp;
		if (temp>max)
			max=temp;
		a/=10;
	}
	printf("%d %d",min,max);

	return 0;
}