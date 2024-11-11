#include <stdio.h>
#include <math.h>
#include <math.h>

int main()
{	
	int a;
	scanf("%d",&a);
	int temp=0;
	int sum=0,ml=1;
	int tmp=0;
	for(int i=10;i<=a;i++)
	{
		sum=0; 
		ml=1;
		tmp=i;
		while(tmp)
		{
			temp=tmp%10;
			tmp/=10;
			sum+=temp;
			ml*=temp;
		}
		if (sum==ml)
			printf("%d ",i);	
	}
	return 0;
}