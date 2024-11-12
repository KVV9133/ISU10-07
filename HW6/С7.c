#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int def(int value,int n)
{	
	int temp=0;
	int st=0;
	while(value!=0)
	{
		temp+=(value%n)*pow(10,st++);
		value=value/n;
	}
	return temp;
};
int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",def(a,b));
	return 0;
}
