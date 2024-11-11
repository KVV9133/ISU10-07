#include <stdio.h>


int main()
{	
	int a;
	int flag=1;
	scanf("%d",&a);
	while(a)
	{
		if ((a%10)&1)
		{
			printf("NO");
			flag=0;
			break;
		}
		a/=10;
	}
	if (flag)
		printf("YES");
	return 0;
}
