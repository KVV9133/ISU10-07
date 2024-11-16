#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int max_find(int max)
{	
	int a;
	scanf("%d",&a);
	if (a==0)
		return max;
	return a>max?max_find(a):max_find(max);
}
 
int main()
{	
	printf("%d ",max_find(1<<31));
    return 0;
}
 

