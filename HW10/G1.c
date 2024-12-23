#include <stdio.h>

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");

	char str[100];
	int i=0;
	int num=0;
	signed char c;
	while((c=fgetc(fr))!=EOF && c!='\n')
	{
		str[i++]=c;	
		num++;
	}
	fprintf(fw,"%s, %s, %s %d",str,str,str,num);

	fclose(fr);
	fclose(fw);


    return 0;
}
 

