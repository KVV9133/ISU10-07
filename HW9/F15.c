int count_bigger_abs(int n, int a[])
{	
	int n1=0;
	int max=0;
	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
	for(int i=0;i<n;i++)
		if(a[i]<0 && -1*a[i]>max)
			n1++;
	 return n1;
} 

