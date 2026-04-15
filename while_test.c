#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define INTERESTA 0.1
#define INTERESTB 0.05
#define MONEY 100
#define END 6
#define PI 3.14


#if 0
static void money(void)
{
	float suma=0;
	float sumb=0;
	int year;
	suma = MONEY + MONEY * INTERESTA;
	printf("A money = %f\n",suma);

	for(year=1;sumb<=suma;year++)
	{
	
	sumb = MONEY * pow((1+INTERESTB),year);
	
	printf("B money = %f\n",sumb);

	}
	printf("%d years ago ,B will pass A!\n",year);
	
	return ;


}

#endif
#if 0
static void count(void)
{
	int number,odd_count=0,even_count=0;
	float odd_sm=0.0,avg_odd=0.0;
	float even_sm=0.0,avg_even=0.0;
	int cnt;
	
	printf("Please input one number:");
	while(1)
	{
	scanf("%d",&number);

	if(number==0)
	break;
	cnt=number%2;
	printf("cnt=%d\n",cnt);
	switch(cnt)
	{
		case 0:
			even_count++;
			even_sm+=number;
			break;
		case 1:
			odd_count++;
			odd_sm+=number;
			break;
		default:
			printf("ERROR!!!\n");
			break;
	}

	printf("Next one:");

	}
	if (odd_count!=0)
	
	{
		avg_odd=odd_sm/odd_count;
	
		printf("The number of odd is %d,the average of add is:%f\n",odd_count,avg_odd);
	}
	if (even_count)
	{
		avg_even=even_sm/even_count;

	printf("The number of even is %d,the average of even is:%f",even_count,avg_even);
	}
	return ;
}
#endif


#if 0
static void test1(void)
{

	int i,j,k;

	for (i=1;i<100/5;i++)
	{
		for(j=1;j<100/3;j++)
		{
			k=100-i-j;
			if( i*5+j*3+k/3==100 && k%3==0)
				printf("%d %d %d\n",i,j,k);
			}
		
		}
	return ;

}
#endif



#if 0
static void test2(void)
{
	int a,b,c;
	int sum=0;
	int number;

	for(number=100;number<1000;number++)
	{
	a=number/100;
	b=number/10%10;
	c=number%10;
	sum = a*a*a+ b*b*b+c*c*c;
	if(sum == number)
		printf("%d is a  armstrong number.\n",number);
	
	}
	return ;




}
#endif


#if 0
static void test3(void)
{

	int i,j;
	
	for (i=0;i<END;i++)
	{
		for(j='A'+i;j<'A'+END;j++)
		{
			printf("%c",j);		
		
		}
	printf("\n");
	
	}
	return ;
}
#endif


#if 0
static void test4(void)
{
	int i,j,flag;
	
	for (i=2;i<1000;i++)
	{
		flag = 1;
		for (j=2;j<i/2;j++)
		{	if(i%j==0)
				{
					flag=0;
				
					break;
				}
		}

	if (flag==1)
	
		printf("%d is a prime number.\n",i);
	}
	
	return ;

}

#endif
//#if 0

static void solid(int row)
{
	int i,j,k;
	if (row%2==1)
	{
	
		for (i=1;i<=row/2+1;i++)		
		{
			for (j=1;j<=(row+1)/2-i;j++)
			{
				printf(" ");
			}
			for (k=1;k<=2*i-1;k++)
			{
				printf("*");
			}
			printf("\n");
		}

		for (i=1;i<=row/2;i++)
		{
			for (j=1;j<=i;j++)
			{
				printf(" ");

			}
			for (k=1;k<=row-2*i;k++)
			{
				printf("*");
			}
			printf("\n");
		}
	
	}
	if (row%2==0)

	{
	
		for (i=1;i<=row/2;i++)		
		{
			for (j=1;j<=row/2-i;j++)
			{
				printf(" ");
			}
			for (k=1;k<=2*i;k++)
			{
				printf("*");
			}
			printf("\n");
		}

		for (i=1;i<=row/2;i++)
		{
			for (j=1;j<=i-1;j++)
			{
				printf(" ");

			}
			for (k=1;k<=(row-2*(i-1));k++)
			{
				printf("*");
			}
			printf("\n");
		}
	return ;
	}	

}
static void hollow(int row)
{
	int i,j,k;
	if (row%2==1)
	{
	
		for (i=1;i<=row/2+1;i++)		
		{
			for (j=1;j<=(row+1)/2-i;j++)
			{
				printf(" ");
			}
			for (k=1;k<=2*i-1;k++)
			{
				if (k==1 || k==2*i-1)
				{
					printf("*");
				
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}

		for (i=1;i<=row/2;i++)
		{
			for (j=1;j<=i;j++)
			{
				printf(" ");

			}
			for (k=1;k<=row-2*i;k++)
			{	
				if(k==1 || k==(row-2*i))
				{
					printf("*");
				}
				else
				{
					printf(" ");
				
				}
			}
			printf("\n");
		}
	
	}
	if (row%2==0)

	{
	
		for (i=1;i<=row/2;i++)		
		{
			for (j=1;j<=row/2-i;j++)
			{
				printf(" ");
			}
			for (k=1;k<=2*i;k++)
			{
				if(k==1 || k==2*i)
				{
					printf("*");
				}
				else
				{
				
					printf(" ");
				}
			}
			printf("\n");
		}

		for (i=1;i<=row/2;i++)
		{
			for (j=1;j<=i-1;j++)
			{

				printf(" ");
			}
			for (k=1;k<=row-2*(i-1);k++)
			{
				if(k==1 || k==row-2*(i-1))
				{
					printf("*");
				}
				else
				{
					printf(" ");
				
				}
			}
			printf("\n");
		}
	return ;
	}
}
static void test5(void)
{
	int row;
	char mode;

	printf("Please input the row and mode(row mode:s or h):");
	if(scanf("%d %c",&row,&mode)==2)
	{

	if (mode=='s')
	{
	solid(row);
	
	}

	if(mode=='h')
	{
	
	hollow(row);

	}
	}
	return ;

}	

//#endif

#if 0
static void test6(void)
{
	int number;
	int sum=0;
	printf("Please input the first integet(Enter q or Q exit):");
	
	
	while(scanf("%d",&number)==1)
	{
		sum+=number;
		printf("Please input the next integet(Enter q or Q exit):");

	}
	printf("The sum of input is:%d\n",sum);
	return ;
}
#endif

#if 0
static void test7(void)
{
	int r=1;
	float area=0;
	int flag = 1;	

	while(flag)
	{
	
		area=PI*r*r;
		if(area>100)
		{
			flag = 0;
			break;
		}
		else
		{
			printf("r=%d area=%f\n",r,area);
			r++;
		}	
	}
	
	return ;
}

#endif

#if 0
static void test8(void)
{
	 int a=1,b=1;
	 printf("%d,%d,",a,b);
	 int tem;
	 int i;
	 for (i=3;i<=40;i++)
	 {
		tem = a + b;
		a = b;
		b = tem;
		printf("%d,",b);
	
	 }
	printf("\n");
	return ;

}
#endif

#if 0
static void test9(void)
{

	int i,j;
	int result;

	for (i=1;i<=9;i++)
	{
		for (j=1;j<=i;j++)
		{
		
			result = i*j;
			printf("%d * %-2d = %d   ",i,j,result);

			
		}
	
		printf("\n\n");
	}

	return ;
}

#endif

#if 0
static void test10(void)
{

	int count=0;
	char alpha;

	printf("Please input one alpha(Enter # exit):");
	
	while(scanf(" %c",&alpha)==1)
	{
		if(alpha=='#')
		{
		
			break;
		
		}
		switch(alpha)
		{
			case 'a':
			case 'A':
		
			case 'e':
			case 'E':
			
			case 'i':
			case 'I':
		
			case 'o':
			case 'O':
		
			case 'u':
			case 'U':
				count++;
				break;
			default:
				break;

		}
		printf("Please input the next alpha(Enter # exit):\n");		
	}
	
		printf("The number of vowel letter is: %d\n",count);
	return ;


}

#endif

int main()
{
//	money();
//	count();
//	test1();
//	test2();
//	test3();
//	test4();
	test5();
//	test6();
//	test7();
//	test8();
//	test9();
//	test10();
	exit(0);
}


















