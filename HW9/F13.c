  int count_between(int from, int to, int size, int a[])
{	
	int sum=0;
	int i=0;
	int n=0;
	int flag=0;
	while(i<size)
	{
		if (a[i]>=from && a[i]<=to)
			flag=1;
		else
			flag=0;
		if (flag)
		{
			sum+=a[i];
			n++;
		}

		i++;
		
	}
	
	return n;
}
