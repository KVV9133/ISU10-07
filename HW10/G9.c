#include <stdio.h>
#include <string.h>

void Sdvig(char* str,int n)
{
	for(int i=n;str[i];i++)
		str[i]=str[i+1];
}

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[1000];
	fscanf(fr,"%[^\n]",str);
	fclose(fr); 
	for(int i=0;str[i];i++)
	{
		if(str[i]==' ')
			{
				Sdvig(str,i);
				i--;
			}
		for(int j=i+1;str[j];j++)
			if(str[j]==str[i])
			{
				Sdvig(str,j);
				i--;
			}
	
	}
	fprintf(fw,"%s",str);
	fclose(fw); 
    return 0;
}
 

