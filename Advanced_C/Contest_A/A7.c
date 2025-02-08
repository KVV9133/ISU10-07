#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	
	int N;
	scanf("%d",&N);
	int result=0;
	int inp;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&inp);
		result^=inp;
	}
	printf("%d",result);

    return 0;
}
