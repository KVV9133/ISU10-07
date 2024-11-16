#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is_prime(int n, int delitel)
{	
	if (n==delitel)
		return 1;
	else if (n<2)
		return 0;
	else if (n%delitel==0)
		return 0;
	return is_prime(n,delitel+1);
}
 
int main()
{	
	int n;
	scanf("%d",&n);
	is_prime(n,2)?printf("YES"):printf("NO");
    return 0;
}
 

