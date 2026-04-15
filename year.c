#include<stdio.h>
#include<stdlib.h>

static void year(void)
{
	int year;
	printf("Please input year:");
	scanf("%d",&year);

	if(( (year%4==0) && (year%100!=0)) || (year%400==0))
		printf("%d is leap year.\n",year);
	else
		printf("%d is commom year.\n",year);
	
	return ;
}


int main()
{

	year();
	exit(0);
}















