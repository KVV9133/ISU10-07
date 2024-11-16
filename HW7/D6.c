#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void reverseString(void)
{
	char c;
	c=getchar();
	if(c!='.')
	{
		reverseString();
		printf("%c",c);
	}
	
}
 
int main()
{
    reverseString();
    return 0;
}
 

