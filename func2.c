#include<stdio.h>
#include<stdlib.h>


int fact(int num)
{

	if (num<0)
	{
		printf("ERROR INPUT!\n");
		return -1;
	}
	else 
	{	if(num == 0 || num==1)
		{
		
			return 1;		
		
		}
		else
		{
			return num *fact(num-1);
		
		}
	}
}

int main()
{
	int num,res;
	printf("Please input a number:");
	if(scanf("%d",&num)==1)
	{
		res=fact(num);
		printf("The factorial of %d is %d\n",num,res);
	}
	
	return 0;
}























