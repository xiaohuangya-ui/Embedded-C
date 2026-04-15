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

#if 0
static void if_two(void)
{
	int score;

	printf("Please input your score: ");
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

#endif



static void swit(void)

{

	int score;
	int sc_ten;

	printf("Please input your score: ");
	if(scanf("%d",&score)!=1)
	{
	printf("NO CORRECT INPUT!!\n");
	return ;
	}


	if(score<0 || score>100)
	{
	printf("INPUT ERROE!!!\n");
	return ;
	
	}
	
	
	sc_ten=score/10;

	switch(sc_ten)
	{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:

			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		
		
		default:
			printf("E\n");
			break;
	}
		return ;
}



int main()
{

	//if_one();
	//if_two();
	swit();
	exit(0);

}




















