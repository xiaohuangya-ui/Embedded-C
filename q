#include<stdio.h>
#include<stdlib.h>




#if 0
static void if_one(void)
{

	int score;


	printf("Please input your sccore:\n");
	scanf("%d",&score);

	if(score<0 || score>100)
	{
	
	printf("INPUT ERROR!!!\n");
	
	}	
	
	
	if(score>=90 && score<=100)
	{
	printf("A\n");
	}
	
	
	if(score>=80 && score<90)
	{
	printf("B\n");
	}
	

	if(score>=70 && score<80)
	{
	printf("C\n");
	}


	if(score>=60 && score<70)
	{
	printf("D\n");
	}

	if(score>=0 && score<60)
	{
	printf("E\n");
	}
	
	return ;	
}

#endif


static void if_two(void)
{
	int score;

	printf("Please input your score:\n ");
	scanf("%d",&score);


	if(score<0 || score>100)
	{
	printf("INPUT ERROE!!!\n");
	}
	

	if (score>=90)
		printf("A\n");
	else if (score>=80)
		printf("B\n");
		else if (score>=70)
			printf("C\n");
			else if(score>60)
				printf("D\n");
				else
				printf("E\n");
	

	return ;
}



int main()
{
//	if_one();
	if_two();
	exit(0);
}


























