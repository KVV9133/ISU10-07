#include <stdio.h>
#include <string.h>
#define size 1000
#define size2 3

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[size2][size]; 
	int i=0;
	while(fscanf(fr,"%s ",str[i++])==1);
	//printf("%s",str);
	fprintf(fw,"Hello, %s %s!",str[1],str[0]);
	fclose(fr);
	fclose(fw); 
    return 0;
}
 

