#include <stdio.h>


int main()
{	
	int a;
	int temp1=0;
	int temp2=10;
	int flag=1;
	scanf("%d",&a);
	while(a)
	{
		temp1=a%10;
		if (temp1<temp2)
			flag=1;
		else
		{	
			flag=0;
			break;
		}
		a/=10;
		temp2=temp1;
	}
	if (flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}