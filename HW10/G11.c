#include <stdio.h>
#include <string.h>
#define size 1000

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[size];
	int n=0;
	while(fscanf(fr,"%s ",str)==1)
	{	
		if (str[strlen(str)-1]=='a')
			n++;
	}

	fprintf(fw,"%d",n);
	fclose(fw); 
    return 0;
}
 

