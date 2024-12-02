//#include <stdio.h>
//#include <math.h>
//#include <inttypes.h>
//#include <stdlib.h>

//int Input(int arr[],int n)
//{
	//int num,  i=0;
	//while(scanf("%d",&num)==1)
		//arr[i++]=num;
	//return i;
//}

void sort_array(int size, int a[])
{
int i=0,j=0,temp=0;
    for(i = 0; i < size; ++i)
    {
        for(j = i; j < size; ++j)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
//void Print(int* arr,int n)
//{
	//for(int i=0;i<n;i++)
		//printf("%d ",arr[i]);
//}

//int main()
//{	
	//enum {BUFFER_SIZE = 20};
	//int arr[BUFFER_SIZE];
	//int n=Input(arr,BUFFER_SIZE);
	//sort_array(n,arr);
	//Print(arr,n);

    //return 0;
//}
 

