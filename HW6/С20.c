#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int is_digit(char c)
{	
	if (c=='(')
		return 1;
	else if (c==')')
		return -1;
	return 0;
};
int main()
{	
	char d;
	int num=0;
	int flag=0;
	while((d=getchar()) && d!='.')
	{
		num+=is_digit(d);
		if (num<0)
		{
			flag=1;
			break;
		}
	}
	if (num==0 && flag==0)
		printf("YES");
	else
		printf("NO");
}
