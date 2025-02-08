#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	unsigned int N,K;
	scanf("%u %u",&N,&K);
	N=(N>>K)|(N<<(32-K));
	printf("%u",N);
    return 0;
}
 
