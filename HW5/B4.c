#include <stdio.h>


int main()
{	
	int a;
	int count=0;
	scanf("%d",&a);
	while(a)
	{
		a/=10;
		count++;	
	}
	if (count==3)
		printf("YES");
	else
		printf("NO");
	return 0;
}