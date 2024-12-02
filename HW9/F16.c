#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

int Input(int arr[])
{
	int num,  i=0;
	while(scanf("%d",&num)==1)
		arr[i++]=num;
	return i;
}
void Input_char(char *ar)
{
	char c;
	int i=0;
	while((c=getchar())!='EOF' && i<2)
		ar[i++]=c;
	ar[i]='\0';
	
}

void Print(int* arr,int n)
{	
	
	for(int i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void func(char *c)
{
		if ((c[0]+c[1])%2==0)
			printf("BLACK");
		else 
			printf("WHITE");
}

int main()
{	

	char a[3];
	Input_char(a);
	func(a);
    return 0;
}
 

