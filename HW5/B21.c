#include <stdio.h>
#include <math.h>


int main()
{	
	char a;
	while((a=getchar()) && a!='.')
	{	
		if (a>=41 && a<=90)
			putchar(a+32);
		else
			putchar(a);
	}
	return 0;
}