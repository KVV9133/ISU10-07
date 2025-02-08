#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	int N;
	scanf("%d",&N);
	int maxValue=1<<31;
	int maxCount=0;
	int value;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&value);
		if(maxValue<value)
		{
			maxValue=value;
			maxCount=1;
		}
		else if(maxValue==value)
		maxCount++;
	}
	printf("%d",maxCount);
    return 0;
}
 
