#include <stdio.h>
#include <string.h>


void BubbleSort(char* str)
{
    int noSwap;
    int n=strlen(str);
    for (int i = 0; i<n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {   
			if(str[j-1]>str[j])
            {
				char temp=str[j];
				str[j]=str[j-1];
				str[j-1]=temp;
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

int check(char *str,char c)
{	
	for(int i=0;str[i];i++)
	{	
		if(c==str[i])
			return 0;
	}
	return 1;
}
int check_1(char *str,char c)
{	
	int num=0;
	for(int i=0;str[i];i++)
	{	
		if(c==str[i])
			num++;
	}
	if (num>1)
		return 0;
	return 1;
}

void func(char* str1,char* str2,char* str3)
{	
	int n=0;
	int num=0;
	//str3[0]='\0';
	for(int i=0;str1[i];i++)
	{	
		for(int j=0;str2[j];j++)
		{
			if(str1[i]==str2[j])
			{
				num++;
			}
		}
		if(num==1 && check_1(str1,str1[i]) )//&& check(str3,str1[i]))
		{
			str3[n++]=str1[i];
			//str3[n++]='\0';
		}
		num=0;		
	}
}

int main()
{	
	FILE *fr;
	FILE *fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	
	char str1[100],str2[100],str3[100];
	fscanf(fr, "%s %s", str1,str2);
	//printf("%s %s",str1,str2);
	func(str1,str2,str3);
	//printf("\n%s ",str3);
	BubbleSort(str3);
	//printf("\n%s ",str3);
	for(int i=0;str3[i];i++)
		fprintf(fw,"%c ",str3[i]);

    return 0;
}
 

