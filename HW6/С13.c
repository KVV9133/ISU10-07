#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int fact(int f)
{
	if (f==0)
		return 1;
	return(f*fact(f-1));
}

float cosinus(int a)
{	
	float x=3.1415*a/180;
	float result=1;
	int st=2,fct=2,zn=-1;
	for(int i=0;i<10;i++)
	{
		result+=zn*pow(x,st)/fact(fct);
		fct+=2;
		st+=2;
		zn*=-1;
	}
	return result;
};
int main()
{	
	int a;
	scanf("%d",&a);
	printf("%.3f",cosinus(a));
	return 0;
}