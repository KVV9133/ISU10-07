#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void def(char *s)
{	
	char *ptr=s;
	while(*ptr!='\0')
	{
	if (*ptr>=97 &&  *ptr<=122)
		*ptr=*ptr-32;	
	ptr++;
	}

};
int main()
{	
	char s[100];
	char* ptr=s;
	while((*(ptr++)=getchar())!='.');
	*(--ptr)='\0';
	def(s);
	printf("%s",s);
	return 0;
}
