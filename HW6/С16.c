#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is_prime(int n)
{	
	if (n<=1)
		return 0;
	int res=1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			res=0;
			break;
		}
	}
	return res;
};
int main()
{	
	int a;
	scanf("%d",&a);
	int d=is_prime(a);
	if (d)
		printf("YES");
	else
		printf("NO");
	return 0;
}
