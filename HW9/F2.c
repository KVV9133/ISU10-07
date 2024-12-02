#include <math.h>
void sort_even_odd(int size, int a[])
{	
	for(int i=size-1;i>=0;i--)
	{	
		for(int j=size-1;j>=0;j--)
			if(abs(a[j])%2==0 && j-1>=0 && abs(a[j-1])%2==1)
			{	
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}	
	}
}
