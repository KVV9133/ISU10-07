#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void func(int n,int k)
{	
	if(n<=0)
		return;
	for(int i=0;i<k&&i<n;i++)
		printf("%d ",k);
	func(n-k,k+1);
}
 
int main()
{	
	int n;
	scanf("%d",&n);
	func(n,1);
    return 0;
}
 

