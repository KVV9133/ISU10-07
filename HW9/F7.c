 int compression(int a[], int b[], int N)
{
	int n=0;
	int curr=0;
	int prev=0;
	int temp=0;
	for (int i=0;i<N;i++)
	{
		curr=a[i];
		if (curr==prev)
		{
			temp++;
			prev=curr;
		}
		else
		{
			b[n++]=temp;
			temp=1;
			prev=curr;
		}
	}
	b[n++]=temp;
	return n;
}