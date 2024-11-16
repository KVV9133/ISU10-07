#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int acounter(void)
{	
	char c;
	c=getchar();
	if(c=='.')
		return 0;
	return (c=='a')+acounter();
	
};
 
int main()
{	
	printf("%d ",acounter());
    return 0;
}
 

