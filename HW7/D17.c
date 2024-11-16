#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int akkerman(int m, int n)
{	
	if(m==0)
		return n+1;
	else if(m>0 && n==0)
		akkerman(m-1,1);
	else if(m>0 && n>0)
		akkerman(m-1,akkerman(m,n-1));
}
 
int main()
{	
	int m,n;
	scanf("%d %d",&m,&n);
	printf("%d ",akkerman(m,n));
    return 0;
}
 

