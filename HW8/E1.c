#include <stdio.h>
#include <math.h>
#include <inttypes.h>


 
int main()
{	
	int mass[5];
	float res=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&mass[i]);
		res+=mass[i];
	}
	printf("%.3f",res/5.0);
    return 0;
}
 

