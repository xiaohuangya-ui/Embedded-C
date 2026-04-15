#include<stdio.h>
#include<stdlib.h>

#define LEFT 1
#define REIGHT 100

#if 0
static void hundred(void)
{

	int i;
	int sum=0;

	for(i=LEFT;i<=REIGHT;i++)
	{	
		sum+=i;

	}
	printf("sum=%d\n",sum);
	return ;

}


#endif

#if 0
static void hundred_two(void)
{
	int i=LEFT;
	int sum = 0;

loop:
	sum+=i;
	i++;

	if(i<=REIGHT)
		goto loop;
	printf("sum=%d\n",sum);
	return ;
}


#endif

int main()
{

//	hundred();
//	hundred_two();

	exit(0);	
}























