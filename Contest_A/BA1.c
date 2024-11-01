#include <stdio.h>
#include <string.h>
#include <locale.h>
void convert10_16(int value,int opt)
{	char x16[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char s[20];
	char *ptr=s;
	while(value!=0)
{	
	if (opt==16)
{
	*(ptr++)=x16[value%16];
	printf("%d",value%16);
	printf("%d",value/16);
	value=value/16;
}
	else 
{	*(ptr++)=x16[value%10];
	printf("%x ",value%10);
	printf("%x ",value/10);
value=value/10;
}
}
	*ptr='\0';
	for(int i=strlen(s)-1;i>=0;i--)
	printf("%c ",s[i]);

};


int main(int argc, char **argv)
{	
setlocale(LC_ALL, "RUS");
int item,value;
while(1)
{
printf("Выберите систему счисления\n");
scanf("%d",&item);
if (item!=10&& item!=16)
	break;
switch (item)
{
case(10):
	scanf("%d",&value);
	convert10_16(value,0);
	break;
case(16):
	scanf("%x",&value);
	convert10_16(value,1);
	break;
}
}


	
	return 0;
}
