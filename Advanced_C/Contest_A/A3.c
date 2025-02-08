#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	unsigned int N,K;
	scanf("%u %u",&N,&K);
	N=N&((1<<(K))-1);
	printf("%u",N);
    return 0;
}
 
