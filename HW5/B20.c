#include <stdio.h>
#include <math.h>


int main()
{	
	int a;
	scanf("%d",&a);
	int flag=0;
	for(int i=2;i<=sqrt(a);i++)
		if (a%i==0)
		{	
			flag=1;
			break;
		}
	if (a==1)
		printf("NO");
	else if (!flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}