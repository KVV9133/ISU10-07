#include <stdio.h>
#include <math.h>

int sumn(int n)
{	
	int summ=0;
	for(int i=1;i<=n;i++)
		summ+=i;
	return summ;
}
int main()
{	
	int a;
	scanf("%d",&a);
	printf("%d",sumn(a));
	return 0;
}
