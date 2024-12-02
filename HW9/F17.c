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

int Sum_D(int arr[][5])
{
	int sum=0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(i==j)
				sum+=arr[i][j];
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
	int arr[5][5];
	Input_matrix(arr);
	printf("%d ",Sum_D(arr));
    return 0;
}
  

