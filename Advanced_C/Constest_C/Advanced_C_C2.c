#include <stdio.h>
#include <string.h>

typedef int datatype;

#define MAX_STACK_SIZE 255

datatype st[MAX_STACK_SIZE];
int pst=0;

void push(datatype v)
{
	st[pst++]=v;
}
datatype pop()
{
	return st[--pst];
}

int isEmpty()
{
	return (pst<=0);
}

void operate(char c)
{
	datatype b = pop();
	datatype a = pop();
	switch (c) 
	{
	  case '+': push(a + b); break;
	  case '-': push(a - b); break;
	  case '*': push(a * b); break;
	  case '/': push(a / b); break;
	}
}

int isDigit(char c)
{
	return ((c>='0')&&(c<='9'));
}

int isOperator(char c)
{
	return c=='+' || c== '-' || c== '*' || c=='/';
}
	
int main(void)
{
	char str[100];
	char c;
	int len=0;
	while((c=getchar())!='\n')
		str[len++]=c;
	str[len]=0;
	for(int i=0;i<len;i++)
	{
		if(isDigit(str[i]))
		{
			datatype number;
			for(number=0;isDigit(str[i]);i++)
				number=number*10+str[i]-'0';
			push(number);
			i--;
		}
		else
		{
			if(i>=len)
				break;
			if(isOperator(str[i]))
				operate(str[i]);
		}
	}
	printf("%d",pop());
	return 0;
}



