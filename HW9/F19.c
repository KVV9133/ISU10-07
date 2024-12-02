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
void Input_matrix(int arr[][5])
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d ",&arr[i][j]);
	
}
void Print_matrix(int arr[][5])
{
	for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
				printf("%d ",arr[i][j]);
			printf("\n");	
		}		
}
int S_D_M(int arr[][5])
{
	int sr_a=0;
	for(int i=0;i<5;i++)
			sr_a+=arr[i][i];
	return sr_a/5;
}


int Max_S_M(int arr[][5], int max)
{
	int n=0;
	for(int i=0;i<5;i++)
	{	
		for(int j=0;j<5;j++)
		{
			if (arr[i][j]>max)
					n++;
		}
	}
	return n;
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



int main()
{	
	int arr[5][5];
	Input_matrix(arr);
	int max=S_D_M(arr);
	printf("%d ",Max_S_M(arr,max));
    return 0;
}
 

