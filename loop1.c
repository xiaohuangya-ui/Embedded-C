#include<stdio.h>
#include<stdlib.h>


#define LEFT 1
#define REIGHT 100
#define END 20

#if 0
static void sum1(void)


{
	int  i=LEFT;
	int sum=0;

	while(i<=REIGHT)
	{
	sum+=i;
	i++;
	
	}

	printf("The sum of %d~%d is:%d\n",LEFT,REIGHT,sum);
	return ;
}


#endif

#if 0
static void sum2(void)
{


	int  i=LEFT;
	int sum=0;


	do
	{
	sum+=i;
	i++;
	}while(i<=REIGHT);

	printf("The sum of %d~%d is:%d\n",LEFT,REIGHT,sum);
	return ;
}
#endif

#if 0
static void test(void)
{

	int start;
	int sum=0;
	
	
	printf("Please input one number:");
	scanf("%d",&start);
	while(start<=END)
	{		

	sum = sum + start;
	start++;
	}
	printf("sum = %d start = %d\n",sum,start);



return ;
}


#endif


static void test1(void)
{

	int start;
	int sum=0;
	
		
	printf("Please input one number:");
	
			

	scanf("%d",&start);
	do		
	{		
	sum = sum + start;
	start++;
	}while(start<=END);
	printf("sum = %d start = %d\n",sum,start);



return ;
}

int main()
{
//	sum1();
//	sum2();

//	test();
	test1();

	exit(0);
}














