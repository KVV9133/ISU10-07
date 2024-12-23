#include <stdio.h>

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");

	int N;
	char c1='A';
	char c2='2';
	fscanf(fr,"%d",&N);
	for(int i=0,j=0;i<N/2;i++,j++)
	{
		fputc(c1+i,fw);
		if(c2+2*j>'8')
			j=0;
		fputc(c2+2*j,fw);
		
	}
	

	fclose(fr);
	fclose(fw);


    return 0;
}
 

