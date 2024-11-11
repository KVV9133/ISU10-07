#include <stdio.h>


int main()
{	
	int a;
	int count=0;
	scanf("%d",&a);
	while(a)
	{
		if (a%10==9)
			count++;
		a/=10;
	}
	if (count==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
