#include<stdio.h>
#include<stdlib.h>

int fib(int num)
{
	if (num<1)
	{
		printf("INPUT ERROR!\n");
		return -1;
	}
	else
	{
		if (num ==1 ||num==2)
		{
		
			return 1;
		}
		else
		{
		
			return fib(num-1)+fib(num-2);
		
		}
	
	}


	
}


int main()
{

	int sub,res;
	printf("Please input th subscript:");
	if(scanf("%d",&sub)==1)
	{
		res=fib(sub);
		printf("The value of the %2d Fibonacci number is:%2d\n",sub,res);
	
	}

	return 0;
}

















