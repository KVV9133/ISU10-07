#include <stdio.h>
#include <string.h>


int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[100];
	fscanf(fr,"%[^\n]",str);
	char c;
	for(int i=0;str[i];i++)
	{	
		c=str[i];
		if (str[i]=='a' || str[i]=='A')
			c=str[i]+1;
		else if(str[i]=='b' || str[i]=='B')
			c=str[i]-1;
		fputc(c,fw);
		
	}

    return 0;
}
 

