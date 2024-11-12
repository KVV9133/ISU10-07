#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int even_odd(int n)
{	
	int temp=0;
	int sum=0;
	while(n!=0)
	{
		temp=n%10;
		sum+=temp;
		n/=10;
	}
	if (sum&1)
		return 0;
	else 
		return 1;
};
int main()
{	
	int a;
	scanf("%d",&a);
	int d=even_odd(a);
	if (d)
		printf("YES");
	else
		printf("NO");
	return 0;
}
