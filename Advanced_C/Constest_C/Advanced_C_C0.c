#include <stdio.h>
#include <string.h>

int main(void) 
{
    char s[1000];
    scanf("%s",s);
    int len = strlen(s)-1;
    if (len<2)
    {
		printf("0");
		return 0;
	}
	int mass[900]={0};

	for(int i=0;i<=len-2;i++)
	{
		if (s[i]=='0')
			continue;
		for(int j=i+1;j<=len-1;j++)
			for(int k=j+1;k<=len;k++)
			{
				int number=(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
				mass[number-100]=1;
			}
	}
	int res =0;
	for(int i=0;i<900;i++)
		res+=mass[i];
		
	printf("%d\n",res);
    return 0;
}
