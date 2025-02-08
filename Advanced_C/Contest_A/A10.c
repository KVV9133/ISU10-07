#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>





int main()
{	
	float f=2.0;
	int *p;
	p=(int*)&f;
	*p=(130)<<23;
	printf("%f",f);

    return 0;
}
