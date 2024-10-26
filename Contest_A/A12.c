#include <stdio.h>

#include <stdio.h>

int main(int argc, char **argv)
{	
	int a;
	scanf("%d",&a);
	int sum=0;
	for(int i=0;i<3;i++)
		{sum+=a%10;
		a/=10;}

	printf("%d",sum);
	return 0;
}
