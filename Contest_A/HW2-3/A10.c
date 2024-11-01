#include <stdio.h>

int main(int argc, char **argv)
{	
	int mass[5];
	int *ptr=mass;
	int count=0;
	
	for(;scanf("%d",ptr++) && count<5;count++);
	int max_element=*mass;
	for(int i=0;i<5;i++)
		if(max_element>=mass[i])
			max_element=mass[i];
	printf("%d",max_element);
	return 0;
}
