#include <stdio.h>

int main(int argc, char **argv)
{	
	int a;
	scanf("%d",&a);
	int max_element=0;
	for(int i=0;i<3;i++)
		{if (max_element<=a%10)
			max_element=a%10;
		a/=10;}

	printf("%d",max_element);
	return 0;
}
