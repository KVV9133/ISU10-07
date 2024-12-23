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
	char str2[1000];
	int max=0;
	while(fscanf(fr,"%s ",str)==1)
	{	
		if(strlen(str)>max)
		{
			strcpy(str2,str);
			max=strlen(str2);
		}
	}

	fprintf(fw,"%s",str2);
	fclose(fw); 
    return 0;
}
 

