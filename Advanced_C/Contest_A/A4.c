#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	unsigned int N,K;
	scanf("%u %u",&N,&K);
	int maxValue=0;
	unsigned int mask=((1<<K)-1);
	for(int i=0;N;i++)
	{
		if ((mask&N)>=maxValue)
		maxValue=mask&N;
		N>>=1;
	}
	printf("%d",maxValue);
    return 0;
}
 
