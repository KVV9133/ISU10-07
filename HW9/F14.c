  int sum_between_ab(int from, int to, int size, int a[])
{	
	int sum=0;
	int i=0;
	int n=0;
	int flag=0;
	int min=from;
	int max=to;
	if(to<from)
	{
		min=to;
		max=from;
	}
	while(i<size)
	{
		if (a[i]>=min && a[i]<=max)
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
	
	return sum;
}
