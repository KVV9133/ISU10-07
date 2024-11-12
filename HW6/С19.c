#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is_digit(char c)
{	
	if (c>='0' && c<='9')
		return c-48;
	else 
		return 0;
};
int main()
{	
	char d;
	int num=0;
	while((d=getchar()) && d!='.')
	{
		num+=is_digit(d);
	}
	printf("%d",num);
}
