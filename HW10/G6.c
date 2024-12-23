#include <stdio.h>
#include <string.h>

int is_palindrome(char *str)
{	
	int len=strlen(str)-1;
	for(int i=0,j=len;i<j;i++,j--)
	{
		if(str[i]!=str[j])
			return 0;
	}
	return 1;
	
}

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	char str[100];
	fscanf(fr,"%[^\n]",str);
	fprintf(fw, "%s", is_palindrome(str)?"YES":"NO");
	fclose(fw); 
	fclose(fr); 
    return 0;
}
 

