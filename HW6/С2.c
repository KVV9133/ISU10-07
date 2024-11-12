#include <stdio.h>
#include <math.h>

int power(int n,int p)
{	
	int ans=1;
	for(int i=0;i<p;i++)
		ans*=n;
	return ans;
}
int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",power(a,b));
	return 0;
}
