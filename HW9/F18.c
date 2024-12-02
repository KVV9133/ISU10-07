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
void Input_matrix(int arr[][10])
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			scanf("%d ",&arr[i][j]);
	
}
void Print_matrix(int arr[][10])
{
	for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
				printf("%d ",arr[i][j]);
			printf("\n");	
		}		
}

int Max_S_M(int arr[][10])
{
	int sum=0;
	int max=0;
	for(int i=0;i<10;i++)
	{	
		max=0;
		for(int j=0;j<10;j++)
		{
			if (arr[i][j]>max)
					max=arr[i][j];
		}
		sum+=max;
	}
	return sum;
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
	int arr[10][10];
	Input_matrix(arr);
	printf("%d ",Max_S_M(arr));
    return 0;
} 

