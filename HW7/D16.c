#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is2pow(unsigned int n)
{	
	if (n==0)
		return 1;
	else if (n&1 && n>1)
		return 0;
	return is2pow(n>>1);
	
};
 
int main()
{	
	unsigned int n;
	scanf("%d",&n);
	is2pow(n)?printf("YES"):printf("NO");
    return 0;
}
 

