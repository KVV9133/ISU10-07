#include <stdio.h>
#include <math.h>


int main()
{	
	int a;
	scanf("%d",&a);
	int val1=1,val2=1;
	int temp=0;
	
	for(int i=0;i<a;i++)
	{	
		if(i<2)
			printf("%d ",val1);
		else
		{
			temp=val1;
			val1=val1+val2;
			val2=temp;
			printf("%d ",val1);
		}
	}
	return 0;
}