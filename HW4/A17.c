#include <stdio.h>

int main(int argc, char **argv)
{	
	int a;
	scanf("%d",&a);
	if (a<=2 || a==12)
	printf("winter");
	else if(a>=3&&a<=5)
	printf("spring");
	else if(a>=6&&a<=8)
	printf("summer");
	else 
	printf("autumn");
	
	return 0;
}
