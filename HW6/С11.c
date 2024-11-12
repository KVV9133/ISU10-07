#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int nod(int a,int b)
{	
	while(a!=0&&b!=0)
	{
		if(a>b)
			a=a%b;
		else 
			b=b%a;
	}
	return a+b;
};
int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",nod(a,b));
	return 0;
}
