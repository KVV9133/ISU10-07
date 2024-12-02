void print_digit(char s[])
{	
	int mass[10]={0};
	int i=0;
	while(s[i]!='\0')
	{	
		

		if(s[i]>='0' && s[i]<='9')
		{
			mass[s[i]-48]++;
		}
		i++;
	}
	for(int i=0;i<10;i++)
	{	
		if(mass[i]!=0)
		printf("%d %d\n",i, mass[i]);
	}
}
