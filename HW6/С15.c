#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int grow_up(int n)
{	
	int temp=0;
	int temp2=10;
	while(n!=0)
	{
		temp=n%10;
		if (temp2<=temp)
			return 0;
		temp2=temp;
		n/=10;
	}
	return 1;
};
int main()
{	
	int a;
	scanf("%d",&a);
	int d=grow_up(a);
	if (d)
		printf("YES");
	else
		printf("NO");
	return 0;
}
