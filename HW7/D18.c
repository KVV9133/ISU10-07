#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void print_digits(int n)
{	
	if(n==0)
		return;
	print_digits(n/10);
	printf("%d ",n%10);
	
};
 
int main()
{	
	unsigned int n;
	scanf("%d",&n);
	print_digits(n);
    return 0;
}
 

