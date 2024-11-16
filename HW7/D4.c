#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int n,int flag)
{
	if (n==0)
	{	if(flag==0)
		{
			printf("0");
			return;
		}
		else
			return;
	}
	func(n/10,1);
	printf("%d ",n%10);	
}

int main()
{
	int n;
	int flag=0;
	scanf("%d",&n);
	func(n,flag);
	
	return 0;	
}
