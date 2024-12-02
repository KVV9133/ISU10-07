 void change_max_min(int size, int a[])
{	
	int min=a[0]; 
	int max=a[1];
	int ind_mn=0,ind_mx=1;
	for(int i=2;i<size;i++)
	{
		if(min>a[i])
		{
		    min=a[i];
		    ind_mn=i;		
		}
		if(max<a[i])
		{
		    max=a[i];
		    ind_mx=i;	
		
		}
	}

	a[ind_mn]=a[ind_mx];
	a[ind_mx]=min;
}
