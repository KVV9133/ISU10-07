#include <stdio.h>
#include <string.h>
#define size 1000

void func(char *str)
{	
	int len = strlen(str);
	for(int i=len-1;i>=0;i--)
	{	
		if(str[i]=='/')
		{
			strcat(str,".html");
			break;
		}
		else if(str[i]=='.')
		{	
			str[i]='\0';
			strcat(str,".html");
			break;
		}
	}
	
}

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[size];
	fscanf(fr,"%[^\n]",str);
	//printf("%s",str);
	func(str);
	//printf("%s",str);
	fprintf(fw,"%s",str);
	fclose(fr);
	fclose(fw); 
    return 0;
}
 

