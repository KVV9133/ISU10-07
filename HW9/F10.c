#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int Input(int arr[])
{
	int num,  i=0;
	while(scanf("%d",&num)==1 && num!=0)
		arr[i++]=num;
	return i;
}

void Ch_Input(char* arr)
{
	char c;
	int i=0;
	while((c=getchar())!='.')
		arr[i++]=c;
	arr[i]='\0';
	
	
}
void Print(int* arr,int n)
{	
	
	for(int i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void func(char* arr,char* b)
{	
	int i=0;
	char curr=arr[0],prev=arr[0];
	int n_1=0;
	int n=0;
	while(arr[i]!='\0')
	{	
		curr=arr[i];
		if(curr==prev)
		{
			n_1++;
		}
		else if(curr!=prev)
		{
			b[n++]=prev;
			char s[5];
			sprintf(s,"%d",n_1);
			strcpy(b+n,s);
			n+=strlen(s);
			n_1=0;
			prev=curr;
			continue;
		}
		
		i++;
	}
	b[n++]=prev;
	char s[5];
	sprintf(s,"%d",n_1);
	strcpy(b+n,s);
	n+=strlen(s);
	b[n]='\0';
}

int main()
{	


	char ar1[1000];
	Ch_Input(ar1);
	char ar2[1000];
	func(ar1,ar2);
	printf("%s",ar2);

    return 0;
} 

