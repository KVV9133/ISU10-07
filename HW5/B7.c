#include <stdio.h>


int main()
{	
	int sp[10]={0};
	int a;
	int temp=0;
	scanf("%d",&a);
	while(a)
	{
		temp=a%10;
		sp[temp]++;
		a/=10;
	}
	for(int i=0;i<10;i++)
	{
		if (sp[i]>=2)
		{
			printf("YES");
			break;
		}
		else if(i==9 && sp[i]<2)
			printf("NO");
	}
	
	return 0;
}