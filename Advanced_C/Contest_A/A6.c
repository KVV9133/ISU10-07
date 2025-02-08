#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	unsigned int N;
	scanf("%u",&N);
	unsigned int mask=((1<<8)-1)<<24;
	printf("%u",mask^N);
	

    return 0;
}
 
