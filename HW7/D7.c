#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int n)
{
	if(n==0)
		return;
	printf("%d ",n);
	func(n-1);
	
}
 
int main()
{	
	int n;
	scanf("%d",&n);
    func(n);
    return 0;
}
 

