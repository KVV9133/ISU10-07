#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is_happy_number(int n)
{	
	int temp=0;
	int mul=1,sum=0;
	while(n!=0)
	{
		temp=n%10;
		mul*=temp;
		sum+=temp;
		n/=10;
	}
	if (mul==sum)
		return 1;
	else 
		return 0;
};
int main()
{	
	int a;
	scanf("%d",&a);
	int d=is_happy_number(a);
	if (d)
		printf("YES");
	else
		printf("NO");
	return 0;
}