#include <stdio.h>
#include <string.h>


int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	//char str[100];
	//fscanf(fr,"%[^\n]",str);
	int n=0,N=0;
	char c;
	while((c=getc(fr))!=EOF)
	{	
		
		if(c>='a' && c<='z')
			n++;
		else if(c>='A' && c<='Z')
			N++;
	}
	fprintf(fw,"%d %d",n,N);
	fclose(fw); 
	fclose(fr); 
    return 0;
}
 

