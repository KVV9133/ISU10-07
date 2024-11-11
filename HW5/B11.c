#include <stdio.h>
#include <math.h>

int main()
{	
	int a;
	
	int value=0;
	scanf("%d",&a);
	int temp=a;
	int count=0;
	while(temp)
	{
		count++;
		temp/=10;
	}
	count--;
	while(a)
	{
		value+=a%10*pow(10,count--);
		a/=10;
	}
	printf("%d",value);

	return 0;
}