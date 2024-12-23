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
	while(fscanf(fr,"%s ",str)==1)
	{	
		fprintf(fw,"%s\n",str);
	}

	fclose(fr);
	fclose(fw); 
    return 0;
}
 

