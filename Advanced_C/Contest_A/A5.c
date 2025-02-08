#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	unsigned int N;
	scanf("%u",&N);
	int Bit_count=0;
	while(N)
	{
		Bit_count+=1&N;
		N>>=1;
	}
	printf("%d",Bit_count);

    return 0;
}
