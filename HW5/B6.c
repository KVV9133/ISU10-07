#include <stdio.h>


int main()
{	
	int a;
	int temp1=0;
	int temp2=-1;
	int flag=0;
	scanf("%d",&a);
	 while(a)
	{
		temp1=a%10;
		if (temp1==temp2)
		{	flag=1;
			printf("YES");
			break;
		}
		a/=10;
		temp2=temp1;
	}
	if (!flag)
		printf("NO");
	return 0;
}
